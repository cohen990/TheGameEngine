#ifndef TGEOBJECT_HPP
#define TGEOBJECT_HPP

#include <vector>

namespace TGE
{
    class Object
    {
    private:
        std::vector<Object> _children;
    public:
        Object();
        void AddChild(Object object);
        void DebugPrint();
    };
}

#endif