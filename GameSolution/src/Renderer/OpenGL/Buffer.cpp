#include "Buffer.h"

VertexBuffer::VertexBuffer() {
	GLCall(glGenBuffers(1, &bufferID));
	bind();
}

VertexBuffer::~VertexBuffer() {
	//Empty
}


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

void IndexBuffer::generateAndAddData(unsigned int quadCount) {
	unsigned int* indexArray = new unsigned int[arraySizeForQuad * quadCount];

	for (int i = 0; i < quadCount; i++) {
		indexArray[i * 6 + 0] = arrayPattern[0] + i * 4;
		indexArray[i * 6 + 1] = arrayPattern[1] + i * 4;
		indexArray[i * 6 + 2] = arrayPattern[2] + i * 4;
		indexArray[i * 6 + 3] = arrayPattern[3] + i * 4;
		indexArray[i * 6 + 4] = arrayPattern[4] + i * 4;
		indexArray[i * 6 + 5] = arrayPattern[5] + i * 4;
	}
	addData<unsigned int>(arraySizeForQuad * quadCount, indexArray);
	delete[] indexArray;
}

void IndexBuffer::bind() {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID));
}

void IndexBuffer::unbind() {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}