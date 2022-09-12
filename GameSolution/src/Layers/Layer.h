#pragma once
#include "../utils/Debugger.h"
#include "../Renderer/BatchRenderer2D.h"
#include "../Events/Event.h"
#include "glm/glm.hpp"
#include <vector>

class Layer {

protected:
	BatchRenderer2D* batchRenderer2D;
	std::vector<glm::mat4> matrizen;


public:
	virtual void handleEvent(Event& e) = 0;
	virtual void render() = 0;
	virtual void init() = 0;


};