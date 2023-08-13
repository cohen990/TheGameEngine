#ifndef TGESHADER_HPP
#define TGESHADER_HPP

namespace TGE::Shaders
{
    class Shader
    {
    private:
        unsigned int _programID;

    public:
        unsigned int ProgramID();
        Shader(const unsigned int programID);
    };
}

#endif