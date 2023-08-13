#ifndef TGEGAME_HPP
#define TGEGAME_HPP

#include <GLFW/glfw3.h>
#include "Objects/TGEobject.hpp"

using namespace TGE::Objects;

namespace TGE
{
    class Game
    {
    private:
        GLFWwindow *_window;
        Object _root;

    public:
        Game(GLFWwindow *window);

        void Destroy();
        void Play();
        void AddObject(Object object) ;
    };
}

#endif
