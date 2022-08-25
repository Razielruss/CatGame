#pragma once
#include "glm/glm.hpp"

struct RenderableData {
	glm::vec3 position;
	glm::vec2 size;
	glm::vec2 texturePosition;
	unsigned int textureID;
};

class Renderable {

protected:
	RenderableData renderableData;

public:

	virtual inline glm::vec3 getPosition() = 0;
	virtual inline glm::vec2 getSize() = 0;
	virtual inline glm::vec2 getTexturePosition() = 0;
	virtual inline unsigned int getTextureID() = 0;
};
