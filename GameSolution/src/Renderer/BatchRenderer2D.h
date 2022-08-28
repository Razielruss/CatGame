#pragma once

#include "OpenGL/Buffer.h"
#include "OpenGL/BufferArray.h"
#include "Renderable.h"
#include "glm/glm.hpp"
#include "../utils/Debugger.h"

class BatchRenderer2D {
private:

	VertexBuffer vertexBuffer;
	IndexBuffer indexBuffer;
	BufferArray bufferArray;
	unsigned int quadCount;
	unsigned int renderCount;

	glm::vec3* buffer;
	void init(unsigned int quadCount);			//Für testzwecke

public:

	BatchRenderer2D(unsigned int quadCount);
	~BatchRenderer2D();

	void begin();
	void submit(Renderable& renderable);
	void flush();
	void end();
};

