#ifndef TGESHADER_HPP
#define TGESHADER_HPP

namespace TGE::Shaders
{
    class Shader
    {
    private:
        unsigned int _programID;
        unsigned int _MVPLocation;

    public:
        unsigned int ProgramID() { return _programID; };
        unsigned int MVPLocation() { return _MVPLocation; };
        Shader(const unsigned int programID);
    };
}

#endif