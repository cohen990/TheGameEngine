#include <iostream>
#include "TGEobject.hpp"

using namespace TGE;

Object::Object(){
}

void Object::AddChild(Object child){
    _children.push_back(child);
}

void Object::DebugPrint(){
    std::cout << this << std::endl;

    for (auto & child : _children) 
    {
        child.DebugPrint();
    }
}