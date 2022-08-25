#include "Charakter.h"

Charakter::Charakter(glm::vec3 position, glm::vec2 size, glm::vec2 texturePosition, unsigned int textureID) {
	renderableData.position = position;
	renderableData.size = size;
	renderableData.texturePosition = texturePosition;
	renderableData.textureID = textureID;
}

Charakter::~Charakter() {

}