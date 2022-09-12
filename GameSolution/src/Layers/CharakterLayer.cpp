#include "CharakterLayer.h"

CharakterLayer::CharakterLayer() {
	batchRenderer2D = new BatchRenderer2D(1);
	shader = new Shader("Resources/Shader.shader", "#defaultVertexShader", "#defaultFragmentShader");
	charakter = new Charakter();
}
CharakterLayer::~CharakterLayer() {
	delete shader;
	delete charakter;
	delete batchRenderer2D;
}

void CharakterLayer::handleEvent(Event& e) {

}

void CharakterLayer::render() {
	shader->bind();
	batchRenderer2D->flush();
	shader->unbind();

}

void CharakterLayer::init() {
	matrizen.push_back(glm::mat4(1.0f));

	batchRenderer2D->begin();
	batchRenderer2D->submit(*charakter);
	batchRenderer2D->end();

}

