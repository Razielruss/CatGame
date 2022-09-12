#include "Camera.h"

Camera::Camera() {

	//Kamera erstellen
	cameraPosition = glm::vec3(0.0f, 0.0f, -2.0f);
	cameraDirection = glm::vec3(0.0f, 0.0f, 0.0f) - cameraPosition;
	cameraRight = glm::cross(upDirection, cameraDirection);

	view = glm::lookAt(cameraPosition, cameraDirection, upDirection);
}

Camera::~Camera() {

}
void Camera::setNewPosition() {

}
void Camera::moveRight() {

}
void Camera::moveLeft() {

}
void Camera::moveUp() {

}
void Camera::moveDown() {

}