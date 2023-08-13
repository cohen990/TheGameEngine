#ifndef TGEOBJECT_HPP
#define TGEOBJECT_HPP

#include <vector>
#include <memory>

namespace TGE::Objects
{
    class Object
    {
    protected:
        std::vector<std::shared_ptr<Object>> _children;
        char* _type;
    public:
        Object();
        void AddChild(std::shared_ptr<Object> object);
        virtual void Render();
        void DebugPrint();
    };
}

#endif