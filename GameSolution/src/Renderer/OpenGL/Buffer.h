#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../../utils/Debugger.h"


class VertexBuffer {

private:
	unsigned int bufferID;
	unsigned int bufferSize;						//Type in sinne von GL_ARRAY_BUFFER oder GL_ELEMENT_ARRAY_BUFFER

public:
	VertexBuffer();
	~VertexBuffer();

	template<typename T>
	void setBufferSize(unsigned int size) {
		bufferSize = size * sizeof(T);
		GLCall(glBufferData(GL_ARRAY_BUFFER, bufferSize, NULL, GL_DYNAMIC_DRAW));

	}

	template<typename T>
	void addData(unsigned int dataLength, T* data) {
		GLCall(glBufferSubData(GL_ARRAY_BUFFER, 0, dataLength * sizeof(T), data));
	}


	//Buffer wird gebunden
	void bind();

	//Buffer wird entbunden
	void unbind();

	enum amountOfData {
		quad = 12,			// Nur Quad (4*3 (vec3) Daten)
		texture = 20,		// Quad mit texture
	};
};


class IndexBuffer {

private:
	unsigned int bufferID;
	unsigned int bufferSize;						//Type in sinne von GL_ARRAY_BUFFER oder GL_ELEMENT_ARRAY_BUFFER
	const unsigned int arraySizeForQuad = 6;


	unsigned int arrayPattern[6] = {
		0, 1, 2,
		1, 2, 3
	};

public:
	IndexBuffer();
	~IndexBuffer();

	template<typename T>
	void setBufferSize(unsigned int size) {
		bufferSize = size * sizeof(T);
		GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, NULL, GL_STATIC_DRAW));

	}

	template<typename T>
	void addData(unsigned int dataLength, T* data) {
		GLCall(glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, dataLength * sizeof(T), data));
	}

	void generateAndAddData(unsigned int quadCount);

	void bind();

	void unbind();
};