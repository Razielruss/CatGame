#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "utils/Debugger.h"


class Camera {
private:
	//Vectoren für die Kamera
	glm::vec3 cameraPosition;
	glm::vec3 cameraDirection;
	glm::vec3 cameraRight;
	glm::vec3 upDirection = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 view;
	float cameraSpeed;

public:
	Camera();
	~Camera();
	void setNewPosition();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

	inline glm::mat4 getView() const {
		return view;
	}

};
