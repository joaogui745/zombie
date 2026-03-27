#include <Music.h>
#include <iostream>

Music::Music() : music(nullptr) {}

Music::Music(std::string file) : music(nullptr){
    Open(file);
}

void Music::Play(int times){
    if (!music){
        std::cerr << "Erro: Música não carregada!" << std::endl;
        exit(EXIT_FAILURE);
    }
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file){
    if (music) Mix_FreeMusic(music);
    music = Mix_LoadMUS(file.c_str());
    if (!music){
        std::cerr << "Erro: Falha ao carregar música: " << file << std::endl;
        std::cerr << "SDL_mixer error: " << Mix_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
}

bool Music::IsOpen() const {
    return music;
}

Music::~Music(){
    Stop();
    Mix_FreeMusic(music);
}