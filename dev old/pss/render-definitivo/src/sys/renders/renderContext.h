#pragma once

struct BitmapContainer_t;

class ImageContext {
public:
    virtual BitmapContainer_t getData() = 0;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
};

struct MeasureText {
    float Width { 0 }, Height { 0 };
};


class IRenderContext {
public:
    explicit IRenderContext() = default;
    virtual ~IRenderContext();

    IRenderContext(IRenderContext&&) = delete;
    IRenderContext(const IRenderContext&) = delete;
    IRenderContext& operator=(IRenderContext&&) = delete;
    IRenderContext& operator=(const IRenderContext&) = delete;

    virtual void fillRect(float x, float y, float w, float h) = 0;
    virtual void strokeRect(float x, float y, float w, float h) = 0;
    virtual void lineWidth(float size) = 0;
    virtual void line(float x1, float y1, float x2, float y2) = 0;
    virtual void setFont(const char* path, float size) = 0;
    virtual void drawText(const char* text, float x, float y) = 0;
    virtual MeasureText measureText(const char* text) = 0;
    virtual void drawImage(ImageContext* image, float x, float y) = 0;
    virtual void drawImage(ImageContext* image, float x, float y, float w, float h) = 0;
    virtual void drawImage(ImageContext* image, float sx, float sy, float sw, float sh, float x, float y, float w, float h) = 0;

    virtual void setColor(unsigned char r, unsigned char g, unsigned char b) = 0;
    virtual void clear(unsigned char r, unsigned char g, unsigned char b) = 0;
    virtual void refresh() = 0;

    virtual void update() = 0;
	virtual bool isRunning() = 0;

    virtual bool isDown(unsigned char keyCode) = 0;

    virtual void setFuncKeyDown(void (*callback)(unsigned char)) = 0 ;
    virtual void setFuncKeyUp(void (*callback)(unsigned char)) = 0 ;
};