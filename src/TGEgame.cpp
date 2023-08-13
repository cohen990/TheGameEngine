#include <iostream>
#include <GLFW/glfw3.h>
#include "TGEgame.hpp"
#include "Objects/TGEroot.hpp"

using namespace TGE;
using namespace TGE::Objects;

Game::Game(GLFWwindow *window)
{
    _window = window;
    _root = Root();
    std::cout << "Started\n";
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
        _root.Render();
		glfwSwapBuffers(_window);
        glfwPollEvents();
    } while (glfwGetKey(_window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(_window) == 0);
}

void Game::AddObject(Object object){
    _root.AddChild(object);
};