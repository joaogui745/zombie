#pragma once
#include <SDL.h>
#include <string>
#include <State.h>


class Game{
private:
    Game(std::string title, int width, int height);
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State state;
public:
    static Game& getInstance();
    ~Game();
    void Run();
    SDL_Renderer* GetRenderer();
    State& GetState();
    
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

};
