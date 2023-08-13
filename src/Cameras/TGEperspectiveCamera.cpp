#include "TGEperspectiveCamera.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace TGE::Cameras;

Camera::Camera() {
	_projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	_view       = glm::lookAt(
								glm::vec3(4,3,3), 
								glm::vec3(0,0,0), 
								glm::vec3(0,1,0)
						   );
	_model      = glm::mat4(1.0f); // remove and see if anything changes // presumably this is so you can add distortions to the camera if you want
}

glm::mat4 PerspectiveCamera::ComputeMVP() {
	return _projection * _view * _model;
}
