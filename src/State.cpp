#include <State.h>
#include <iostream>
#include <cstdlib>


State::State() : bg(), music(), quitRequested(false) {}

State::~State(){
    objectArray.clear();
}

void State::LoadAssets(){
    bg.Open("img/Background.png");
    music.Open("audio/BGM.wav");
    music.Play();
}

void State::Update(float dt){
    if (SDL_QuitRequested()) {
        quitRequested = true;
    }

    for (auto& go : objectArray){
        go->Update(dt);
    }

    size_t idx = 0;
    while (idx < objectArray.size()) {
        if (objectArray[idx]->IsDead()) {
            objectArray.erase(objectArray.begin() + idx);
        } else {
            ++idx;
        }
    }

}

void State::Render(){
    //bg.Render(0, 0); //Keep this (?)
    for (auto& go : objectArray){
        go->Render();
    }
}

void State::AddObject(GameObject* go){
    if (go == nullptr){
        std::cerr << "Erro ao adicionar objeto" << std::endl;
        exit(EXIT_FAILURE);
    }
    objectArray.emplace_back(go);
}

bool State::QuitRequested() const {
    return quitRequested;
}