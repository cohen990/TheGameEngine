#ifndef TGEMESH_HPP
#define TGEMESH_HPP

#include <vector>
#include "TGEobject.hpp"
#include "../Shaders/TGEshader.hpp"

namespace TGE::Objects
{
    class Mesh : public Object
    {
    private:
        unsigned int _vertexBuffer;
        TGE::Shaders::Shader *_shader;

    public:
        Mesh(float *vertices, unsigned long verticesLength, TGE::Shaders::Shader *shader);
        void Render() override;
    };
}

#endif