#include "../header/Game.h"

Game::Game() {

	windowWidth = 1024;
	windowHeight = 768;

	run = initOpenGL();
	shader = new Shader("Resources/Shader.shader", "#defaultVertexShader", "#defaultFragmentShader");
	charakterSprite = new Sprite("Resources/Bilder/KatzeAnimation.png", 0);
	charakter = new Charakter(*charakterSprite);

	vertexBuffer = new Buffer(GL_ARRAY_BUFFER);
	indexBuffer = new Buffer(GL_ELEMENT_ARRAY_BUFFER);
	arrayBuffer = new BufferArray();

	run = initGame();
}

Game::~Game() {
	delete shader;
	delete charakterSprite;
	delete charakter;

	delete vertexBuffer;
	delete indexBuffer;
}


void Game::process() {

	/* Loop until the user closes the window */
	int i = 0;
	float time = 0;
	bool right = true;
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		if (glfwGetTime() > time) {
			if (right == true) {
				shader->setUniform2f("shift", (((i % 4) + 1) * 64.0f) / charakterSprite->getSpriteWidth(), 0.0f / charakterSprite->getSpriteHeight());
			}
			else {
				shader->setUniform2f("shift", (((i % 4) + 1) * 64.0f) / charakterSprite->getSpriteWidth(), -64.0f / charakterSprite->getSpriteHeight());
			}
			i++;
			time += 0.2f;
			if ((i % 5) == 0 && right == true) {
				right = false;
				continue;
			}
			if ((i % 5) == 0 && right == false) {
				right = true;
			}


		}
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

}

//private Methoden

bool Game::initGame() {

	shader->bind();
	shader->setUniform1i("ourTexture", charakterSprite->getSlot());
	charakterSprite->bind();

	//Buffer
	vertexBuffer->bind();
	vertexBuffer->setBufferSizeF(charakter->getDataSize());
	vertexBuffer->addDataF(charakter->getDataSize(), charakter->getData());

	indexBuffer->bind();
	indexBuffer->setBufferSizeUI(charakter->getIndexDataSize());
	indexBuffer->addDataUI(charakter->getIndexDataSize(), const_cast<unsigned int*>(charakter->getIndexData()));


	arrayBuffer->addLayoutF(0, 2, 4, 0);
	arrayBuffer->addLayoutF(1, 2, 4, 2);
	arrayBuffer->aktivateAllLayouts();

	return true;
}

bool Game::initOpenGL() {

	if (!glfwInit()) {
		return false;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(windowWidth, windowHeight, "WonderCat", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "error" << std::endl;
		return false;
	}

	glfwSetKeyCallback(window, keyCallBack);
	return true;
}

void Game::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
	LOG("funktioniert");
}