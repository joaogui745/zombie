#include <Game.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>

Game& Game::getInstance() {
    static Game instance("Zumbi", 800, 600);
    return instance;
}

Game::Game(std::string title, int width, int height) : state() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)){
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)){
        std::cerr << "Loaders não carregados" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!Mix_Init(MIX_INIT_MP3)){
        std::cerr << "Decoders não carregados" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096)){
        std::cerr << "Mix_OpenAudio Error" << std::endl;
        exit(EXIT_FAILURE);
    }

    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    
    if (window == nullptr) {
        std::cerr << "Erro ao criar janela" << std::endl;
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr){
        std::cerr << "Erro ao criar renderer" << std::endl;
        exit(EXIT_FAILURE);
    }
}

Game::~Game() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

SDL_Renderer* Game::GetRenderer(){
    return renderer;
}

State& Game::GetState(){
    return state;
}

void Game::Run(){
    while (!state.QuitRequested()){
        state.Update(0.0);
        state.Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
    
}

