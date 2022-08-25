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
		GLCall(glBufferData(GL_ARRAY_BUFFER, bufferSize, NULL, GL_STATIC_DRAW));

	}

	//Buffer wird gebunden
	void bind();

	//Buffer wird entbunden
	void unbind();
};


class IndexBuffer {

private:
	unsigned int bufferID;
	unsigned int bufferSize;						//Type in sinne von GL_ARRAY_BUFFER oder GL_ELEMENT_ARRAY_BUFFER

public:
	IndexBuffer();
	~IndexBuffer();

	template<typename T>
	void setBufferSize(unsigned int size) {
		bufferSize = size * sizeof(T);
		GLCall(glBufferData(GL_ARRAY_BUFFER, bufferSize, NULL, GL_STATIC_DRAW));

	}

	void addData(unsigned int dataLength, unsigned int* data);

	void bind();

	void unbind();
};