#pragma once
#include <SDL.h>
#include <string>

class Sprite {
private:
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;
public:
    Sprite();
    Sprite(std::string);
    ~Sprite();

    void Open(std::string file);
    void SetClip(int x, int y, int width, int height);
    void Render(int x, int y);
    int GetWidth() const;
    int Getheight() const;
    bool IsOpen() const;
};