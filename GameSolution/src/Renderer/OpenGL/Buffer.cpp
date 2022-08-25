#include "Buffer.h"

VertexBuffer::VertexBuffer() {
	GLCall(glGenBuffers(1, &bufferID));
	bind();
}

VertexBuffer::~VertexBuffer() {
	//Empty
}

/*
void Buffer::addDataF(unsigned int dataLength, float* data) {
	if ((offset + dataLength * sizeof(float)) <= bufferSize) {
		GLCall(glBufferSubData(bufferType, offset, dataLength * sizeof(float), data));
		offset = offset + dataLength * sizeof(float);
	}
	else {
		LOG("Buffer zu klein");
	}
}
*/

void VertexBuffer::bind() {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, bufferID));
}

void VertexBuffer::unbind() {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}


//IndexBuffer
IndexBuffer::IndexBuffer() {
	GLCall(glGenBuffers(1, &bufferID));
	bind();
}

IndexBuffer::~IndexBuffer() {
	//Empty
}

void IndexBuffer::addData(unsigned int dataLength, unsigned int* data) {
	GLCall(glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, dataLength * sizeof(unsigned int), data));
}


void IndexBuffer::bind() {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID));
}

void IndexBuffer::unbind() {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}