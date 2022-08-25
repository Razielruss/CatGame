#pragma once
#include "Renderable.h"
#include "../Events/Event.h"

class Charakter : public Renderable {

private:
	float vilocity;
	bool contactWithObject;

public:
	Charakter(glm::vec3 position = glm::vec3(0, 0, 0), glm::vec2 size = glm::vec2(0.5, 0.5),
		glm::vec2 texturePosition = glm::vec2(0, 0), unsigned int textureID = -1);
	~Charakter();

	void handelEvent(Event& e);

	virtual inline glm::vec3 getPosition() {
		return renderableData.position;
	}
	virtual inline glm::vec2 getSize() {
		return renderableData.size;
	}
	virtual inline glm::vec2 getTexturePosition() {
		return renderableData.texturePosition;
	}
	virtual inline unsigned int getTextureID() {
		return renderableData.textureID;
	}
};