#include <iostream>
#include "TGEmesh.hpp"
#include "../Shaders/TGEshader.hpp"
#include "../Cameras/TGEcamera.hpp"
#include <GL/glew.h>

using namespace TGE::Objects;

Mesh::Mesh(float *vertices, unsigned long sizeOfVertices, TGE::Shaders::Shader *shader)
{
    _type = "Mesh";
    _shader = shader;
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeOfVertices, vertices, GL_STATIC_DRAW);
    _vertexBuffer = vertexBuffer;
}

void Mesh::Render(TGE::Cameras::Camera* camera)
{
    glUseProgram(_shader->ProgramID());
    glEnableVertexAttribArray(0);
    glUniformMatrix4fv(_shader->MVPLocation(), 1, GL_FALSE, &camera->ComputeMVP()[0][0]);
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
    TGE::Objects::GameObject::Render(camera);
}