#pragma once

#include <SDL.h>
#include <memory>
#include <vector>
#include <Sprite.h>
#include <Music.h>
#include <GameObject.h>

class State {
private:
    Music music;
    bool quitRequested;
    std::vector<std::unique_ptr<GameObject>> objectArray;

public:
    State();
    ~State();
    void AddObject(std::unique_ptr<GameObject> go);
    bool QuitRequested() const;
    void LoadAssets();
    void Update(float dt);
    void Render();
};