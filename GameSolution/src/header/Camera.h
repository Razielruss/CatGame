#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>

#include "Debugger.h"

class Camera {
private:
	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;

	// float yaw, pitch;			vielleicht brauchbar

	glm::mat4 view;
	float cameraSpeed;
	float timeStep;

	float deltaTime, lastTime;

public:
	Camera();
	~Camera();

	void input(GLFWwindow* window);

	glm::mat4 getView() const {
		return view;
	}
};