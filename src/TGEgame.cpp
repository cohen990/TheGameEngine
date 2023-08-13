#include <iostream>
#include <memory>
#include <GLFW/glfw3.h>
#include "TGEgame.hpp"
#include "Objects/TGEroot.hpp"
#include "Cameras/TGEcamera.hpp"

using namespace TGE;
using namespace TGE::Objects;
using namespace TGE::Cameras;

Game::Game(GLFWwindow *window)
{
    _window = window;
    _root = Root();
    std::cout << "Started\n";
    _camera = new Camera();
}

void Game::Destroy()
{
    std::cout << "Ended\n";
}

void Game::Play()
{
    std::cout << "Playing\n";
    
    _root.DebugPrint();
    do
    {
		glClear( GL_COLOR_BUFFER_BIT);
        _root.Render(_camera);
		glfwSwapBuffers(_window);
        glfwPollEvents();
    } while (glfwGetKey(_window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(_window) == 0);
}

void Game::AddObject(std::shared_ptr<GameObject> object){
    _root.AddChild(object);
};

void Game::AddCamera(TGE::Cameras::Camera* camera)
{
    _camera = camera;
}