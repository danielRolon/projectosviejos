#include <sys/renders/rago/renderAgo.h>

#include <iostream>

RenderAgo2D::RenderAgo2D(int width, int height, char* title) {
    Width = width;
    Height = height;
    Title = title;
    Running = true;

    //Allegro Setup Error Message
    if(!al_init()) {
        al_show_native_message_box(nullptr,nullptr,nullptr,"Allegro couldnt initialize",nullptr,0);
    }

    //Screen Resolution
    Display = al_create_display(Width, Height);

    //Allegro Screen Creating Error
    if(!Display) {
        al_show_native_message_box(nullptr,nullptr,nullptr,"Couldnt create Screen",nullptr,0);
    }

    //Title
    //al_set_app_name("Culo");
    al_set_window_title(Display, Title);

    //Init Font
    al_init_font_addon();
    al_init_ttf_addon();

    //Init Primitives
    al_init_primitives_addon();

    //Init Keyboard
    al_install_keyboard();

    //Init Image
    al_init_image_addon();

    //Timer
    Timer = al_create_timer(1.0 / FPS_OBJETIVO);

    // Init Event Queue
    EventQueue = al_create_event_queue();

    // Register events
    al_register_event_source(EventQueue, al_get_keyboard_event_source());
    al_register_event_source(EventQueue, al_get_display_event_source(Display));
    al_register_event_source(EventQueue, al_get_timer_event_source(Timer));

    // Start Timer
    al_start_timer(Timer);
}

RenderAgo2D::~RenderAgo2D() {
    al_destroy_display(Display);
    al_destroy_event_queue(EventQueue);
    al_destroy_font(CurrentFont);
    al_destroy_timer(Timer);

    std::cout << "Destroy RenderAllegro2D\n";
}

void RenderAgo2D::fillRect(float x, float y, float w, float h) {
    al_draw_filled_rectangle(x, y, x + w, y + h, al_map_rgb(Rgb.r, Rgb.g, Rgb.b));
}

void RenderAgo2D::strokeRect(float x, float y, float w, float h) {
    al_draw_rectangle(x, y, x + w, y + h, al_map_rgb(Rgb.r, Rgb.g, Rgb.b), LineThickness);
}

void RenderAgo2D::lineWidth(float size) {
    LineThickness = size;
}

void RenderAgo2D::line(float x1, float y1, float x2, float y2) {
    al_draw_line(x1, y1, x2, y2, al_map_rgb(Rgb.r, Rgb.g, Rgb.b), LineThickness);
}

void RenderAgo2D::setFont(const char* path, float size) {
    ALLEGRO_FONT* font = al_load_font(path, size, 0);

    if (CurrentFont == font || !font) return;
    if (CurrentFont) al_destroy_font(CurrentFont);
    CurrentFont = font;
}

void RenderAgo2D::drawText(const char* text, float x, float y) {
    al_draw_text(CurrentFont, al_map_rgb(Rgb.r, Rgb.g, Rgb.b), x, y, 0, text);

}

MeasureText RenderAgo2D::measureText(const char* text) {
    MeasureText measureText;
    measureText.Width = al_get_text_width(CurrentFont, text);
    measureText.Height = al_get_font_line_height(CurrentFont);

    return measureText;
}

void RenderAgo2D::drawImage(ImageContext* image, float x, float y) {
    al_draw_scaled_bitmap(image->getData().data, 0, 0, image->getWidth(), image->getHeight(), x, y, image->getWidth(), image->getHeight(), 0);
}

void RenderAgo2D::drawImage(ImageContext* image, float x, float y, float w, float h) {
    al_draw_scaled_bitmap(image->getData().data, 0, 0, image->getWidth(), image->getHeight(), x, y, w, h, 0);
}

void RenderAgo2D::drawImage(ImageContext* image, float sx, float sy, float sw, float sh, float x, float y, float w, float h) {
    al_draw_scaled_bitmap(image->getData().data, sx, sy, sw, sh, x, y, w, h, 0);
}

void RenderAgo2D::setColor(unsigned char r, unsigned char g, unsigned char b) {
    Rgb.r = r;
    Rgb.g = g;
    Rgb.b = b;
}

void RenderAgo2D::clear(unsigned char r, unsigned char g, unsigned char b) {
    al_clear_to_color(al_map_rgb(r, g, b));
}

void RenderAgo2D::refresh() {
    al_flip_display();
}

void RenderAgo2D::update() {
    al_wait_for_event(EventQueue, &Event);

    if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        Running = false;
    }

    if (Event.type == ALLEGRO_EVENT_KEY_DOWN) {
        if (p_FuncKD) p_FuncKD(Event.keyboard.keycode);
    }

    if (Event.type == ALLEGRO_EVENT_KEY_UP) {
        if (p_FuncKU) p_FuncKU(Event.keyboard.keycode);
    }
}

bool RenderAgo2D::isRunning() {
    return Running;
}

bool RenderAgo2D::isDown(unsigned char keyCode) {
    if (Event.type == ALLEGRO_EVENT_KEY_CHAR) {
        if (keyCode == Event.keyboard.keycode) return true;
    }

    return false;
}

void RenderAgo2D::setFuncKeyDown(void (*callback)(unsigned char)) {
    p_FuncKD = callback;        
}

void RenderAgo2D::setFuncKeyUp(void (*callback)(unsigned char)) {
    p_FuncKU = callback;
}
