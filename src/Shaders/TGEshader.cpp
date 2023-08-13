#include "TGEshader.hpp"

using namespace TGE::Shaders;

TGE::Shaders::Shader::Shader(const unsigned int programID)
{
    _programID = programID;
}

unsigned int TGE::Shaders::Shader::ProgramID(){
    return _programID;
}