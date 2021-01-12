#pragma once

#include <console/console.h>
#include <stddef.h>
#include <inttypes.h>
#include <string>

#define C_BLACK			 0 
#define C_BLUE			 1
#define C_GREEN			 2
#define C_CYAN			 3
#define C_RED			 4
#define C_MAGENTA		 5
#define C_YELLOW		 6
#define C_LIGHT_GRAY 	 7
#define C_DARK_GRAY 	 8
#define C_LIGHT_BLUE	 9
#define C_LIGHT_GREEN 	10
#define C_LIGHT_CYAN 	11
#define C_LIGHT_RED 	12
#define C_LIGHT_MAGENTA 13
#define C_LIGHT_YELLOW  14
#define C_WHITE         15
#define C_LIGHT         8

#define CONSOLE_ROWS    = 150;
#define CONSOLE_COLUMNS = 80;

struct Image16
{
	inline Image16(const char* colors, size_t width, size_t height)
		: colors(colors), width(width), height(height)
	{

	}

	inline ~Image16()
	{
		delete[]colors;
	}

	inline size_t       getWidth()  const { return width; }
	inline size_t       getHeight() const { return height; }
	inline const char*  getColors()  const { return colors; }

private:
	const char* colors = nullptr;
	const char* path   = nullptr;
	size_t width = 0, height = 0;
};

namespace Console
{
	class Render
	{
	public:
		//Init
		static void Init();
		static void Free();

		//Image
		static Image16* LoadImage15T(const std::string& path);
		static Image16* LoadPPM(const std::string& path);
		static void DrawImage15T(Image16* pImage15T, size_t x, size_t y);

		//Primitives
		static void Clear();
		static void Flush();
		static void SetColor(unsigned short color);
		static void DrawPixel(int x, int y);
		static void DrawRect(size_t x, size_t y, size_t w, size_t h);
		static void FillRect(size_t x, size_t y, size_t w, size_t h);
		static void DrawCircle(float Xc, float Yc, float r);
		static void FillCircle(float Xc, float Yc, float r);

		//Help
		static void Gotoxy(int x, int y);
	public:
		inline static constexpr int screenWidth  = 150;
		inline static constexpr int screenHeight = 80;
	private:
		inline static wchar_t *screenChars  = new wchar_t[screenWidth*screenHeight];
		inline static WORD    *screenColors = new WORD[screenWidth*screenHeight];
		inline static HANDLE  console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		inline static DWORD   dwBytesWriten = 0;

		inline static unsigned short Color = 0;
	};
}