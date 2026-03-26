#include <Game.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>

Game& Game::getInstance() {
    static Game instance("Zumbi", 800, 600);
    return instance;
}

Game::Game(string title, int width, int height){
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)){
        cerr << "SDL_Init Error: " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }

    if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)){
        cerr << "Loaders não carregados" << endl;
        exit(EXIT_FAILURE);
    }

    if (!Mix_Init(MIX_INIT_MP3)){
        cerr << "Decoders não carregados" << endl;
        exit(EXIT_FAILURE);
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096)){
        cerr << "Mix_OpenAudio Error" << endl;
        exit(EXIT_FAILURE);
    }

    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    
    if (window == nullptr) {
        cerr << "Erro ao criar janela" << endl;
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr){
        cerr << "Erro ao criar renderer" << endl;
        exit(EXIT_FAILURE);
    }

    // Criar State (TODO)

}
