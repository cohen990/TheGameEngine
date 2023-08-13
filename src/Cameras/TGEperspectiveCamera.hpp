#ifndef TGEPERSPECTIVECAMERA_HPP
#define TGEPERSPECTIVECAMERA_HPP

#include <glm/glm.hpp>
#include "TGEcamera.hpp"

namespace TGE::Cameras
{
    class PerspectiveCamera : public TGE::Cameras::Camera
    {
    public:
        PerspectiveCamera();
        glm::mat4 ComputeMVP() override;
    };
}

#endif