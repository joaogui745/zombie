#include <Sprite.h>
#include <Game.h>
#include <SDL_image.h>
#include <iostream>
#include <cstdlib>

Sprite::Sprite() : texture(nullptr){}

Sprite::Sprite(std::string file, int frameCountW, int frameCountH) : texture(nullptr),  frameCountW(frameCountW), frameCountH(frameCountH) {
    Open(file);
}

Sprite::~Sprite(){
    if (texture) SDL_DestroyTexture(texture);
}

void Sprite::SetClip(int x, int y, int width, int height){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = width;
    clipRect.h = height;
}

void Sprite::Open(std::string file){
    if (texture) SDL_DestroyTexture(texture);
    texture = IMG_LoadTexture(Game::getInstance().GetRenderer(), file.c_str());
    
    if (!texture){
        std::cerr << "Erro ao carregar textura do arquivo: " << file << std::endl;
        exit(EXIT_FAILURE);
    }
    
    if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height)) {
        std::cerr << "Erro ao consultar textura" << std::endl;
        exit(EXIT_FAILURE);
    }

    SetClip(0, 0, width, height);
}

void Sprite::Render(int x, int y, int width, int height) {
    SDL_Rect dstRect = { x, y, clipRect.w, clipRect.h };
    SDL_RenderCopy(Game::getInstance().GetRenderer(), texture, &clipRect, &dstRect);
}

void Sprite::SetFrame(int frame){
    if (frameCountW == 0 || frameCountH == 0){
        std::cerr << "Invalid Frame count" << std::endl;
        exit(EXIT_FAILURE);
    }

    int frameW = GetFrameWidth();
    int frameH = GetFrameHeight();
    int totalFrames = frameCountW * frameCountH;

    if (frame < 0 || frame >= totalFrames) {
        std::cerr << "Frame index out of range: " << frame << std::endl;
        exit(EXIT_FAILURE);
    }

    int row = frame / frameCountW;
    int col = frame % frameCountW;

    int x = col * frameW;
    int y = row * frameH;

    if (x < 0 || y < 0 || x + frameW > width || y + frameH > height) {
        std::cerr << "Calculated clip is outside sprite bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    SetClip(x, y, frameW, frameH);
}

void Sprite::SetFrameCount(int frameCountW, int frameCountH){
    if (frameCountW <= 0 || frameCountH <= 0) {
        std::cerr << "Invalid frame count" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->frameCountW = frameCountW;
    this->frameCountH = frameCountH;
}

int Sprite::GetWidth() const {
    return width;
}

int Sprite::Getheight() const {
    return height;
}

bool Sprite::IsOpen() const{
    return texture;
}

int Sprite::GetFrameWidth() const {
    return width / frameCountW;
}

int Sprite::GetFrameHeight() const {
    return height / frameCountH;
}
