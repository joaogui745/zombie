#include <State.h>
#include <iostream>
#include <cstdlib>
#include <SpriteRenderer.h>


State::State() : music(), quitRequested(false) {
}

State::~State(){
    objectArray.clear();
}

void State::LoadAssets(){
    auto bg = std::make_unique<GameObject>();
    bg->AddComponent(new SpriteRenderer(*bg, "img/Background.png"));
    AddObject(std::move(bg));
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
    for (auto& go : objectArray){
        go->Render();
    }
}

void State::AddObject(std::unique_ptr<GameObject> go) {
    if(!go) exit(EXIT_FAILURE);
    objectArray.emplace_back(std::move(go));
}

bool State::QuitRequested() const {
    return quitRequested;
}