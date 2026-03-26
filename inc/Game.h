#pragma once
#include <SDL.h>
#include <string>

using namespace std;

class Game{
    public:
    static Game& getInstance();
    ~Game();

    void Run();
    SDL_Renderer* GetRenderer();
    //State& GetState();

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    private:
    Game(string title, int width, int height);

    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    //State state;

};
