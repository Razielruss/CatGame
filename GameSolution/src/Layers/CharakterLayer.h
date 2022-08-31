#pragma once
#include "Layer.h"
#include "../Renderer/Charakter.h"
#include "../Renderer/OpenGL/Shader.h"

class CharakterLayer : public Layer {
private:
	Charakter* charakter;
	Shader* shader;
public:
	CharakterLayer();
	~CharakterLayer();

	void handleEvent(Event& e) override;
	void render() override;
	void init() override;

};