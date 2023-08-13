#ifndef TGEOBJECT_HPP
#define TGEOBJECT_HPP

#include <vector>

namespace TGE::Objects
{
    class Object
    {
    protected:
        std::vector<Object> _children;
        char* _type;
    public:
        Object();
        void AddChild(Object object);
        virtual void Render();
        void DebugPrint();
    };
}

#endif