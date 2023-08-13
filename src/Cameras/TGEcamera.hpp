#ifndef TGECAMERA_HPP
#define TGECAMERA_HPP

#include <glm/glm.hpp>

namespace TGE::Cameras
{
    class Camera
    {
    protected:
        glm::mat4 _projection;
        glm::mat4 _view;
        glm::mat4 _model;

    public:
        Camera();
        virtual glm::mat4 ComputeMVP();
    };
}

#endif