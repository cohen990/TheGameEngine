#include "TGEengine.hpp"
#include "TGEgame.hpp"
#include "TGEwindowManager.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

using namespace TGE;

Game TGE::CreateGame()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return nullptr;
	}
	GLFWwindow *window = CreateWindow();
	if (window == nullptr)
	{
		std::cerr << "Failed to initialise the game\n";
		glfwTerminate();
		return nullptr;
	}
	return Game(window);
}

void TGE::TearDown()
{
	glfwTerminate();
}