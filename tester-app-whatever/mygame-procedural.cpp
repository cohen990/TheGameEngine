#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <boost/optional.hpp>
#include <string>
#include <ios>
#include <fstream>
#include <sstream>

#include "../src/Shaders/TGEbuiltInShaders.hpp"
#include "../src/Objects/TGEmesh.hpp"

int main()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}
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
		return -1;
	}

	glfwMakeContextCurrent(window);
	if (window == nullptr)
	{
		std::cerr << "Failed to create the game window\n";
		glfwTerminate();
		return -1;
	}
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		glfwTerminate();
		return -1;
	}
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

    float vertices[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
    };

    boost::optional<TGE::Shaders::Shader> shader = TGE::Shaders::SimpleShader();
    if (!shader)
    {
        std::cout << "failed to load the simple shader. Exiting." << std::endl;
        return -1;
    }
	TGE::Objects::Mesh mesh = TGE::Objects::Mesh(vertices, &*shader);
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    do
    {
		glClear( GL_COLOR_BUFFER_BIT);

        glUseProgram(shader->ProgramID());
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glVertexAttribPointer(
            0,        // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,        // size
            GL_FLOAT, // type
            GL_FALSE, // normalized?
            0,        // stride
            (void *)0 // array buffer offset
        );

		glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
		glDisableVertexAttribArray(0);
		mesh.Render();

		glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(window) == 0);
}