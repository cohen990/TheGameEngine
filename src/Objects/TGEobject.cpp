#include <iostream>
#include <memory>
#include "TGEobject.hpp"

using namespace TGE::Objects;

Object::Object(){
    _type = "Object";
}

void Object::AddChild(std::shared_ptr<Object> child){
    _children.push_back(child);
}

void Object::DebugPrint(){
    std::cout << _type << " at address: " << this << std::endl;

    for (auto & child : _children) 
    {
        child->DebugPrint();
    }
}

void Object::Render(){
    for (auto & child : _children) 
    {
        child->Render();
    }
}