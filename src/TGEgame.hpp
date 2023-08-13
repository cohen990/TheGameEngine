#ifndef TGEGAME_HPP
#define TGEGAME_HPP

#include <GLFW/glfw3.h>
#include <memory>
#include "Objects/TGEgameObject.hpp"
#include "Cameras/TGEcamera.hpp"

namespace TGE
{
    class Game
    {
    private:
        GLFWwindow *_window;
        TGE::Objects::GameObject _root;
        TGE::Cameras::Camera* _camera;

    public:
        Game(GLFWwindow *window);

        void Destroy();
        void Play();
        void AddObject(std::shared_ptr<TGE::Objects::GameObject> object) ;
        void AddCamera(TGE::Cameras::Camera* camera);
    };
}

#endif
