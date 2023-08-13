#ifndef TGEGAMEOBJECT_HPP
#define TGEGAMEOBJECT_HPP

#include <vector>
#include <memory>

#include "../Cameras/TGEcamera.hpp"

namespace TGE::Objects
{
    class GameObject
    {
    protected:
        std::vector<std::shared_ptr<GameObject>> _children;
        char* _type;
    public:
        GameObject();
        void AddChild(std::shared_ptr<GameObject> object);
        virtual void Render(TGE::Cameras::Camera* camera);
        void DebugPrint();
    };
}

#endif