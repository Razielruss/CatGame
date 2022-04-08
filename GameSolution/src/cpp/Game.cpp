#include "../header/Game.h"

Game::Game() {

	windowWidth = 1024.0f;
	windowHeight = 768.0f;

	run = initOpenGL();
	shader = new Shader("Resources/Shader.shader", "#defaultVertexShader", "#defaultFragmentShader");
	charakterSprite = new Sprite("Resources/Bilder/KatzeAnimation.png", 0);
	charakter = new Charakter(*charakterSprite);

	vertexBuffer = new Buffer(GL_ARRAY_BUFFER);
	indexBuffer = new Buffer(GL_ELEMENT_ARRAY_BUFFER);
	arrayBuffer = new BufferArray();

	run = initGame();

	//tomp�rer
	cameraPos = glm::vec3(0.0f, 0.0f, 2.0f);
	cameraFront = glm::vec3(0.0f, 0.0f, -2.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	view = glm::lookAt(cameraPos, cameraFront, cameraUp);

	firstMouse = true;
	lastX = windowWidth / 2;
	lastY = windowHeight / 2;

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
	//glm::mat4 transformation = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, -10.0f, 10.0f);
	glm::mat4 transformation = glm::perspective(glm::radians(45.0f), windowWidth / windowHeight, 0.1f, 10.0f);

	LOG(cameraPos.x, cameraPos.y, cameraPos.z);
	while (!glfwWindowShouldClose(window))
	{

		float currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		/* Render here */
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		if (glfwGetTime() > time) {
			//charakter nach rechts laufen lassen
			if (right == true) {
				shader->setUniform2f("shift", (((i % 4) + 1) * 64.0f) / charakterSprite->getSpriteWidth(), 0.0f / charakterSprite->getSpriteHeight());
			}

			//charakter nach links laufen lassen
			else {
				shader->setUniform2f("shift", (((i % 4) + 1) * 64.0f) / charakterSprite->getSpriteWidth(), -64.0f / charakterSprite->getSpriteHeight());
			}
			i++;
			time += 0.2f;

			//Logik um Techtur nach rechts und links plotten zu lassen
			if ((i % 5) == 0 && right == true) {
				right = false;
				continue;
			}
			if ((i % 5) == 0 && right == false) {
				right = true;
			}

			//Kamera Logik
			view = glm::lookAt(cameraPos, cameraFront, cameraUp);
			shader->setUniformM4fv("view", 1, glm::value_ptr(view));
			shader->setUniformM4fv("transformation", 1, glm::value_ptr(transformation));
			shader->setUniform3f("move", debugger.move.x, debugger.move.y, 0.0f);

		}
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

}

void Game::cameraTest() {

	//Debug Shader erstellen
	Shader debugShader("Resources/Shader.shader", "#debugCameraVertexShader", "#debugCameraFragmentShader");
	debugShader.bind();
	glm::mat4 transformation = glm::perspective(glm::radians(45.0f), windowWidth / windowHeight, -2.0f, 2.0f);
	//glm::mat4 transformation = glm::ortho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);
	debugShader.setUniformM4fv("transformation", 1, glm::value_ptr(transformation));

	Buffer vertexBuffer(GL_ARRAY_BUFFER);
	vertexBuffer.setBufferSizeF(debugger.cubeLength);
	vertexBuffer.addDataF(debugger.cubeLength, debugger.cube);
	BufferArray layout;
	layout.addLayoutF(0, 3, 3, 0);
	layout.aktivateAllLayouts();

	cameraPos = glm::vec3(0.0f, 0.0f, -2.0f);
	cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
	cameraUp = glm::vec3(1.0f, 0.0f, 0.0f);

	LOG(cameraPos.x, cameraPos.y, cameraPos.z);
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		view = glm::lookAt(cameraPos, cameraFront, cameraUp);
		debugShader.setUniformM4fv("view", 1, glm::value_ptr(view));
		//debugShader.setUniform3f("move", debugger.move.x, 0.0f, 0.0f);

		glDrawArrays(GL_TRIANGLES, 0, 36);

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
	glfwSetCursorPosCallback(window, mouse_callback);
	return true;
}



void Game::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	float cameraSpeed = 10.0f * deltaTime;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {// brauch man nicht
		cameraPos += cameraSpeed * cameraFront;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		cameraPos -= cameraSpeed * cameraFront; //brauch man nicht
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		glm::vec3 temp = glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		cameraPos.x -= temp.x;
		debugger.move.x -= temp.x;
		cameraFront.x -= temp.x;
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		glm::vec3 temp = glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		cameraPos.x += temp.x;
		debugger.move.x += temp.x;
		cameraFront.x += temp.x;
	}

	LOG(cameraPos.x, cameraPos.y, cameraPos.z);
}



void Game::mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	float xFinal;
	float yFinal;
	/*
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}
	*/
	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.1f; // change this value to your liking
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (pitch > 89.0f) {
		pitch = 89.0f;
	}
	if (pitch < -89.0f) {
		pitch = -89.0f;
	}

	glm::vec3 temp;
	temp.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	temp.y = sin(glm::radians(pitch));
	temp.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	//cameraFront = glm::normalize(temp);
	//LOG(cos(glm::radians(lastX)));

}