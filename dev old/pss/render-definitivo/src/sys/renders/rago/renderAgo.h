#pragma once

#include <sys/renders/renderContext.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

//IMAGE--------------------------------------------------|
#include <sys/renders/rago/loadImgMan.h>               //|
                                                       //|
struct BitmapContainer_t {                             //|
    ALLEGRO_BITMAP* data;                              //|
};                                                     //|
                                                       //|
class Image : public ImageContext {            //|
public:                                                //|
    explicit Image(const char* path)  {         //|
        data = LoadImgMan::LoadImage(path);            //|
        width = al_get_bitmap_width(data);             //|
        height = al_get_bitmap_width(data);            //|
    }                                                  //|
    ~Image() {                                  //|
        al_destroy_bitmap(data);                       //|
    }                                                  //|
    BitmapContainer_t getData() override {             //|
        return {data};                                 //|
    }                                                  //|
    int getWidth() const override { return width; }    //|
    int getHeight() const override { return height; }  //|
private:                                               //|
    int width { 0 }, height { 0 };                     //|
    ALLEGRO_BITMAP* data { nullptr };                  //|
};                                                     //|
//IMAGE--------------------------------------------------|

struct ColorRbg_t {
    unsigned char r = 0, g = 0, b = 0;
};

class RenderAgo2D : public IRenderContext {
public:
    RenderAgo2D(int width, int height, char* title);
    ~RenderAgo2D();

    void fillRect(float x, float y, float w, float h) override ;
    void strokeRect(float x, float y, float w, float h) override ;
    void lineWidth(float size) override ;
    void line(float x1, float y1, float x2, float y2) override ;
    void setFont(const char* path, float size) override ;
    void drawText(const char* text, float x, float y) override ;
    MeasureText measureText(const char* text) override ;
    void drawImage(ImageContext* image, float x, float y) override ;
    void drawImage(ImageContext* image, float x, float y, float w, float h) override ;
    void drawImage(ImageContext* image, float sx, float sy, float sw, float sh, float x, float y, float w, float h) override ;

    void setColor(unsigned char r, unsigned char g, unsigned char b) override ;
    void clear(unsigned char r, unsigned char g, unsigned char b) override ;
    void refresh() override ;

    void update() override ;
    bool isRunning() override ;

    bool isDown(unsigned char keyCode) override ;

    void setFuncKeyDown(void (*callback)(unsigned char)) override ;
    void setFuncKeyUp(void (*callback)(unsigned char)) override ;

private:
    int fpsCount = 0;
    int FPS_OBJETIVO = 60;

    bool   Running  = false;
    int    Width    = 640;
    int    Height   = 360;
    char * Title    = "My first windows with allegro";

    ALLEGRO_EVENT        Event;
    ALLEGRO_FONT*        CurrentFont  = nullptr;
    ALLEGRO_TIMER*       Timer        = nullptr;
    ALLEGRO_DISPLAY*     Display      = nullptr;
    ALLEGRO_EVENT_QUEUE* EventQueue   = nullptr;
    ColorRbg_t Rgb { 0, 0, 0 };

    void(*p_FuncKD)(unsigned char) { nullptr };
    void(*p_FuncKU)(unsigned char) { nullptr };

    float LineThickness = 1;
};