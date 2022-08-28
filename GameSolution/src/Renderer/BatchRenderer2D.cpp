#include "BatchRenderer2D.h"



//private functionen
void BatchRenderer2D::init(unsigned int quadCount) {

	//Kann später gelöscht werden
	float rectAngle[VertexBuffer::amountOfData::quad] = {
	0.2f, -0.2f, 0.0f,
	0.2f, 0.2f, 0.0f,
	-0.2f, -0.2f, 0.0f,
	-0.2f, 0.2f, 0.0f
	};


	vertexBuffer.bind();
	vertexBuffer.setBufferSize<float>(quadCount * VertexBuffer::amountOfData::quad);
	vertexBuffer.addData(VertexBuffer::amountOfData::quad, rectAngle);


	indexBuffer.bind();
	indexBuffer.setBufferSize<unsigned int>(quadCount * 6);

	indexBuffer.generateAndAddData(quadCount);

	bufferArray.addLayout<float>(0, 3, 3, 0);
	bufferArray.aktivateAllLayouts();

	//indexBuffer.unbind();
	//vertexBuffer.unbind();
}
//public functionen
BatchRenderer2D::BatchRenderer2D(unsigned int quadCount) :quadCount(quadCount) {
	init(quadCount);
	renderCount = 0;
}
BatchRenderer2D::~BatchRenderer2D() {

}

void BatchRenderer2D::begin() {

	vertexBuffer.bind();
	indexBuffer.bind();
	buffer = (glm::vec3*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
}

void BatchRenderer2D::submit(Renderable& renderable) {

	glm::vec3 position = renderable.getPosition();
	glm::vec2 size = renderable.getSize();

	*buffer = glm::vec3(position.x, position.y, 0.0f);
	buffer++;

	*buffer = glm::vec3(position.x + size.x, position.y, 0.0f);
	buffer++;

	*buffer = glm::vec3(position.x, position.y - size.y, 0.0f);
	buffer++;

	*buffer = glm::vec3(position.x + size.x, position.y - size.y, 0.0f);
}
void BatchRenderer2D::flush() {
	vertexBuffer.bind();
	indexBuffer.bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	vertexBuffer.unbind();
	indexBuffer.bind();
}

void BatchRenderer2D::end() {
	glUnmapBuffer(GL_ARRAY_BUFFER);
	vertexBuffer.unbind();
	indexBuffer.unbind();
}