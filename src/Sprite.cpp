#include <Sprite.h>
#include <Game.h>
#include <SDL_image.h>
#include <iostream>

Sprite::Sprite() : texture(nullptr){}

Sprite::Sprite(std::string file) : texture(nullptr) {
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

void Sprite::Render(int x, int y) {
    SDL_Rect dstRect = { x, y, clipRect.w, clipRect.h };
    SDL_RenderCopy(Game::getInstance().GetRenderer(), texture, &clipRect, &dstRect);
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
