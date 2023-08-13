#include "TGEshader.hpp"
#include <GL/glew.h>

using namespace TGE::Shaders;

TGE::Shaders::Shader::Shader(const unsigned int programID)
{
    _programID = programID;
    _MVPLocation = glGetUniformLocation(programID, "MVP"); 
}