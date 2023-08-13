#include <iostream>
#include "TGEmesh.hpp"
#include "../Shaders/TGEshader.hpp"
#include <GL/glew.h>

using namespace TGE::Objects;

Mesh::Mesh(float *vertices, unsigned long sizeOfVertices, TGE::Shaders::Shader *shader)
{
    std::cout << "length of vertices " << sizeOfVertices << std::endl;
    std::cout << "vertices " << vertices << std::endl;
    _type = "Mesh";
    _shader = shader;
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeOfVertices, vertices, GL_STATIC_DRAW);
    _vertexBuffer = vertexBuffer;
}

void Mesh::Render()
{
    glUseProgram(_shader->ProgramID());
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
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
    for (auto &child : _children)
    {
        child.Render();
    }
}