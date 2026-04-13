#include <GameObject.h>
#include <Component.h>
#include <algorithm>
#include <iostream>

GameObject::GameObject() : isDead(false){}

GameObject::~GameObject(){
	for (auto idx = components.rbegin(); idx != components.rend(); ++idx) {
        delete *idx;
    }
	components.clear();
}

void GameObject::Update(float dt) {
    for (Component* component : components) {
        component->Update(dt);
    }
}

void GameObject::Render() {
    for (Component* component : components) {
        component->Render();
    }
}

bool GameObject::IsDead() const{
    return isDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component* cmpPtr){
    if (cmpPtr == nullptr){
        std::cerr << "Component is null" << std::endl;
        exit(EXIT_FAILURE);
    }
    components.push_back(cmpPtr);
}

void GameObject::RemoveComponent(Component* cmpPtr){
    auto idx = std::find(components.begin(), components.end(), cmpPtr);
    if (idx != components.end()){
        components.erase(idx);
    }
}

template <typename T>
T* GameObject::GetComponent() {
    for (Component* c : components) {
        T* component = dynamic_cast<T*>(c);
        if (component != nullptr) {
            return component;
        }
    }
    return nullptr;
}