#include "BufferArray.h"

BufferArray::BufferArray() {
	glGenVertexArrays(1, &bufferID);
	glBindVertexArray(bufferID);
}

BufferArray::~BufferArray() {

}

void BufferArray::aktivateLayout(unsigned int index) {
	Layout layout = bufferLayouts.at(index);

	GLCall(glEnableVertexAttribArray(layout.index));
	GLCall(glVertexAttribPointer(layout.index, layout.size, GL_FLOAT, GL_FALSE, layout.stride, (void*)layout.offset));
}

void BufferArray::aktivateAllLayouts() {


	for (std::vector<Layout>::iterator iterator = bufferLayouts.begin(); iterator != bufferLayouts.end(); iterator++) {
		GLCall(glEnableVertexAttribArray(iterator->index));
		GLCall(glVertexAttribPointer(iterator->index, iterator->size, GL_FLOAT, GL_FALSE, iterator->stride, (void*)iterator->offset));
	}

}