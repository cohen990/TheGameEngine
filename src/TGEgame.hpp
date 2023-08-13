#ifndef TGEGAME_HPP
#define TGEGAME_HPP

#include <GLFW/glfw3.h>
#include <memory>
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
        void AddObject(std::shared_ptr<Object> object) ;
    };
}

#endif
