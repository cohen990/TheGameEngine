#include <GLFW/glfw3.h>
#include <stdio.h>

#include "TGEwindowManager.hpp"

GLFWwindow* TGE::CreateWindow()
{
	GLFWwindow *window;
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1024, 768, "Your Game", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to open the window");
		getchar();
		return NULL;
	}
	return window;

	glfwMakeContextCurrent(window);
}