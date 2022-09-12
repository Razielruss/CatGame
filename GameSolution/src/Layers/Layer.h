#pragma once
#include "../Renderer/BatchRenderer2D.h"
#include "../Events/Event.h"
#include "glm/glm.hpp"
#include <vector>
#include "../Windows/WindowsWindow.h"

class Layer {

protected:
	BatchRenderer2D* batchRenderer2D;
	std::vector<glm::mat4> matrizen;
	static unsigned int heightFromWindow, widthFromWindow; //Für Layer die die perspektive rendern

public:
	virtual void handleEvent(Event& e) = 0;
	virtual void render() = 0;
	virtual void init() = 0;

	static void setSizesFromWindow(WindowsWindow& window);
};

