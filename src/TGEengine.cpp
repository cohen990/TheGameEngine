#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "TGEengine.hpp"
#include "TGEgame.hpp"
#include "TGEwindowManager.hpp"
#include <iostream>
#include <boost/optional.hpp>

using namespace TGE;

boost::optional<Game> TGE::CreateGame()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return boost::none;
	}
	GLFWwindow *window = CreateWindow();
	if (window == nullptr)
	{
		std::cerr << "Failed to create the game window\n";
		glfwTerminate();
		return boost::none;
	}
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		glfwTerminate();
		return boost::none;
	}
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	return Game(window);
}

void TGE::TearDown()
{
	glfwTerminate();
}