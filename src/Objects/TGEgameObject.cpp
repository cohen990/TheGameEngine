#include <iostream>
#include <memory>
#include "TGEgameObject.hpp"
#include "../Cameras/TGEcamera.hpp"

using namespace TGE::Objects;

GameObject::GameObject(){
    _type = "GameObject";
}

void GameObject::AddChild(std::shared_ptr<GameObject> child){
    _children.push_back(child);
}

void GameObject::DebugPrint(){
    std::cout << _type << " at address: " << this << std::endl;

    for (auto & child : _children) 
    {
        child->DebugPrint();
    }
}

void GameObject::Render(TGE::Cameras::Camera* camera){
    for (auto & child : _children) 
    {
        child->Render(camera);
    }
}