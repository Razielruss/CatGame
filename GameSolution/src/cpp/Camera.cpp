#include "../header/Camera.h"


Camera::Camera() {
	cameraPos = glm::vec3(0.0f, 0.0f, 2.0f);
	cameraFront = glm::vec3(0.0f, 0.0f, -2.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	view = glm::lookAt(cameraPos, cameraFront, cameraUp);

	cameraSpeed = 1.0f;

	timeStep = 0.0f;
	deltaTime = 0.0f;
	lastTime = 0.0f;
}
Camera::~Camera() {
	//Leer
}

void Camera::input(GLFWwindow* window) {

	deltaTime = glfwGetTime() - lastTime;
	lastTime = glfwGetTime();

	if (glfwGetTime() > timeStep) {
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
			glm::vec3 temp = glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * deltaTime;
			cameraPos.x -= temp.x;
			cameraFront.x -= temp.x;
		}

		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
			glm::vec3 temp = glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * deltaTime;
			cameraPos.x += temp.x;
			cameraFront.x += temp.x;
		}
		view = glm::lookAt(cameraPos, cameraFront, cameraUp);
		timeStep += 0.02f;
	}
}
