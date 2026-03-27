#include <State.h>


State::State() : bg(), music(), quitRequested(false) {}

void State::LoadAssets(){
    bg.Open("img/Background.png");
    music.Open("audio/BGM.wav");
    music.Play();
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