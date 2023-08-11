#include <iostream>
#include <GLFW/glfw3.h>
#include "TGEgame.hpp"
#include "TGEobject.hpp"

using namespace TGE;

Game::Game(GLFWwindow *window)
{
    _window = window;
    _root = Object();
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
        glfwPollEvents();
    } while (glfwGetKey(_window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(_window) == 0);
}

void Game::AddObject(Object object){
    _root.AddChild(object);
};