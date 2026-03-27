#include <State.h>


State::State() : bg("img/Background.png"), quitRequested(false) {}

void State::LoadAssets(){
    // Carregar assets
}

void State::Update(float dt){
    if (SDL_QuitRequested()) {
        quitRequested = true;
    }
}

void State::Render(){
    bg.Render(0, 0);
}

bool State::QuitRequested() const {
    return quitRequested;
}