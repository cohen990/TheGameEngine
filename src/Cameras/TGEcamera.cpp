#include "TGEcamera.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace TGE::Cameras;

Camera::Camera() { }

glm::mat4 Camera::ComputeMVP() {
	return glm::mat4(1.0f);
}
