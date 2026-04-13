#pragma once
#include <SDL.h>
#include <string>

class Sprite {
private:
    SDL_Texture* texture;
    int width; 
    int height;
    int frameCountW;
    int frameCountH;
    SDL_Rect clipRect;
public:
    Sprite();
    Sprite(std::string file, int frameCountW = 1, int frameCountH = 1);
    ~Sprite();

    void Open(std::string file);
    void SetClip(int x, int y, int width, int height);
    void Render(int x, int y, int width, int height);
    
    void SetFrame(int frame);
    void SetFrameCount(int frameCountW, int frameCountH);
    int GetWidth() const;
    int Getheight() const;
    int GetFrameWidth() const;
    int GetFrameHeight() const;
    bool IsOpen() const;
};