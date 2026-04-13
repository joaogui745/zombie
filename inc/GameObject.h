#pragma once

#include <vector>
#include <Rect.h>

class Rect;
class Component;

class GameObject {
private:
    std::vector<Component*> components;
    bool isDead;
public:
    GameObject();
    ~GameObject();
    void Update(float dt);
    void Render();
    bool IsDead() const;
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    template<typename T> T* GetComponent();
    Rect box;
};