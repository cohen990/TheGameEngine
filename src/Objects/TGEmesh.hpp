#ifndef TGEMESH_HPP
#define TGEMESH_HPP

#include <vector>
#include "TGEgameObject.hpp"
#include "../Shaders/TGEshader.hpp"
#include "../Cameras/TGEcamera.hpp"

namespace TGE::Objects
{
    class Mesh : public GameObject
    {
    private:
        unsigned int _vertexBuffer;
        TGE::Shaders::Shader *_shader;

    public:
        Mesh(float *vertices, unsigned long verticesLength, TGE::Shaders::Shader *shader);
        void Render(TGE::Cameras::Camera* camera) override;
    };
}

#endif