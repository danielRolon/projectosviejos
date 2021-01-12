#include <console/render.h>
#include <math.h>
#include <fstream>
#include <sstream>
#include <tools/handleText.h>
#include <vector>

#define INDEX_PPM_TYPE          0
#define INDEX_PPM_COMMENT       1
#define INDEX_PPM_WIDTH_HEIGHT  2
#define INDEX_PPM_MAX_RGB       3
#define INDEX_PPM_IMAGE         4

#define RGBTO15C(x,z) if (x <= 85)        \
                        x = 0;            \
                      else if (x <= 170)  \
                        x = z;            \
                      else                \
                        x = (z | C_LIGHT)


namespace Console
{
    //Init
    void Render::Init()
    {
        SetConsoleActiveScreenBuffer(console);
    }

    void Render::Free()
    {
        delete[] screenChars;
        delete[] screenColors;
    }

    //Image
    Image16* Render::LoadImage15T(const std::string& path)
    {
        std::ifstream stream(path);
        std::string line;
        std::stringstream colors;
        size_t width = 0, height = 0;
        int i = 0;
        while(getline(stream, line))
        {
            switch (i)
            {
            case 0:
                width = atoi(line.c_str());
                break;

            case 1:
                height = atoi(line.c_str());
                break;
            default:
                colors << line;
                break;
            }
            ++i;
        }
        
        std::string str = colors.str();
        std::cout << str.c_str() << "\n";
        char* copy_str = new char[width*height];
        memcpy(copy_str, str.c_str(), width*height);
        Image16* image15T = new Image16(copy_str, width, height);
        return image15T;
    }

    Image16* Render::LoadPPM(const std::string& path)
    {
        struct Rgb
        {
            Rgb() {}
            int R = 0, G = 0, B = 0;
        };

        bool done = false;

        std::ifstream stream(path);
        std::string line;
        std::vector<Rgb> RGBs;

        int width = 0, height = 0, index_ppm = 0, count_rgb = 0;

        while (getline(stream, line))
        {
            // OBTENER ALTO Y ANCHO DE LA IMAGEN
            if (index_ppm == INDEX_PPM_WIDTH_HEIGHT)
            {
                char** splited = split(line.c_str(), ' ');
                width  = atoi(splited[0]);
                height = atoi(splited[1]); 
            }

            // AÑADIR COLORES EN RGB
            if (index_ppm >= INDEX_PPM_IMAGE)
            {
                Rgb& rgb = RGBs.emplace_back();
                rgb.R = atoi(line.c_str()); getline(stream, line); ++index_ppm;
                rgb.G = atoi(line.c_str()); getline(stream, line); ++index_ppm;
                rgb.B = atoi(line.c_str());
            }
            ++index_ppm;
        }

         //TRANSFORMAR EL FORMATO RGB AL DE 16 COLORES DE LA CONSOLA

        char* colors = new char[width*height+1];

        for (int i = 0; i < width*height; ++i)
        {
            Rgb& rgb = RGBs[i];

            RGBTO15C(rgb.R, C_RED);
            RGBTO15C(rgb.G, C_GREEN);
            RGBTO15C(rgb.B, C_BLUE);

            int value = (rgb.R | rgb.G |rgb.B);

            switch(value)
            {
                case C_LIGHT_GRAY:
                {
                    value = 15;
                    break;
                }
            }

            colors[i] = (char) (value + 48);
        }

        colors[width*height] = '\0';

        Image16* image16 = new Image16(colors, width, height);

        return image16;
    }

    void Render::DrawImage15T(Image16* pImage15T, size_t x, size_t y)
    {
        size_t width = pImage15T->getWidth();
        size_t height = pImage15T->getHeight();
        const char* colors = pImage15T->getColors();

        for (int j = 0; j < height; ++j)
        {
            for (int i = 0; i < width ; ++i)
            {
                SetColor(int(colors[i + j * width]));
                DrawPixel(i + x, j + y);
            }
        }
    }


    //Primitives
    void Render::Clear()
    { 
        //FillConsoleOutputAttribute(console)
        //FillConsoleOutputCharacterW(console, L' ', screenWidth*screenHeight, { 0, 0 }, &dwBytesWriten);
		for (int i = 0; i < screenWidth*screenHeight; i++)
		{
			screenChars[i]  = ' ';
			screenColors[i] = C_BLACK;
		}

    }

    void Render::Flush()
    {
		screenChars[screenWidth*screenHeight-1] = '\0';
		screenColors[screenWidth*screenHeight-1] = '\0';

        WriteConsoleOutputCharacterW(console, screenChars, screenWidth*screenHeight, { 0, 0 }, &dwBytesWriten);
    	WriteConsoleOutputAttribute(console, screenColors, screenWidth*screenHeight, { 0, 0 }, &dwBytesWriten);
    }

    void Render::SetColor(unsigned short color)
    {
        Color = color;
    }

    void Render::DrawPixel(int x, int y)
    {
         screenChars[x + y * screenWidth] = 0x2588;//0x2588
         screenColors[x + y * screenWidth] = Color;
    }

    void Render::DrawRect(size_t x, size_t y, size_t w, size_t h)
    {
        for (int dy = y; dy <= y + h; ++dy)
        {
            for (int dx = x; dx <= x + w; ++dx)
            {
                if (dx == x || dy == y || dx == x + w || dy == y + h)
                DrawPixel(dx, dy);
            }  
        }
    }

    void Render::FillRect(size_t x, size_t y, size_t w, size_t h)
    {
        for (int dy = y; dy <= y + h; ++dy)
        {
            for (int dx = x; dx <= x + w; ++dx)
            {
                DrawPixel(dx, dy);
            }  
        }
    }

    void Render::DrawCircle(float Xc, float Yc, float r)
    {
        float x = 0, y = r;
        float p = (5/4)-r;

        while(x <= y)
        {
            DrawPixel(x + Xc, y + Yc);
            DrawPixel(y + Xc, x + Yc);
            DrawPixel(-x + Xc, -y + Yc);
            DrawPixel(-y + Xc, -x + Yc);
            DrawPixel(x + Xc, -y + Yc);
            DrawPixel(-y + Xc, x + Yc);
            DrawPixel(-x + Xc, y + Yc);
            DrawPixel(y + Xc, -x + Yc);   

            if (p <= 0)
            {
                ++x;
                p = p + (2 * x) + 1;
            }
            else
            {
                ++x;
                --y;
                p = p + (2 * x) - (2 * y) + 1;
            }
        }
    }

    void Render::FillCircle(float Xc, float Yc, float r)
    {
        for (;r > 0; --r)
        {
            float x = 0, y = r;
            float p = (5/4)-r;
    
            while(x <= y)
            {
                int x0 = round(x);
                int y0 = round(y);
                DrawPixel(x0 + Xc, y0 + Yc);
                DrawPixel(y0 + Xc, x0 + Yc);
                DrawPixel(-x0 + Xc, -y0 + Yc);
                DrawPixel(-y0 + Xc, -x0 + Yc);
                DrawPixel(x0 + Xc, -y0 + Yc);
                DrawPixel(-y0 + Xc, x0 + Yc);
                DrawPixel(-x0 + Xc, y0 + Yc);
                DrawPixel(y0 + Xc, -x0 + Yc);   

                if (p <= 0)
                {
                    ++x;
                    p = p + (2 * x) + 1;
                }
                else
                {
                    ++x;
                    --y;
                    p = p + (2 * x) - (2 * y) + 1;
                }
            }  
        }
    }

    //Help
    void Render::Gotoxy(int x, int y){ 
        COORD coord; 
        coord.X = x; coord.Y = y; 
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  
    } 
}