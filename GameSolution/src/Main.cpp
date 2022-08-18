#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Application.h"
#include <functional>
#include "Events/Event.h";
#include "Events/KeyEvents.h"

/*
class A {

public:
	A() {

	}
	void onEvent(Event& e) {
		std::cout << e.getEventName().c_str() << std::endl;
	}

};

using namespace std::placeholders;
*/
int main(void)
{
	/*
	A a;
	KeyPress kp;
	auto b = std::bind(&A::onEvent, &a, _1);

	std::function<void(Event&)> test = b;
	b(kp);
	*/
	Application app;
	app.runApplication();
	/*
	GLFWwindow* window;


	if (!glfwInit())
		return -1;



	window = glfwCreateWindow(1024, 768, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "error" << std::endl;
	}
	loadSprite();
	float height = 63.0f, width = 63.0f;
	//sicher gehen das es funktioniert hier der Code der später in Klassen aufgeteilt wird
	float rectAngle[4 * 4] = {
		0.2f, 0.2f,	  width / spriteWidth, 1.0f,//oben rechts
		0.2f, -0.2f,  width / spriteWidth, (spriteHeight - height) / spriteHeight,//unten rechts
		-0.2f, -0.2f, 0.0f, (spriteHeight - height) / spriteHeight,//unten links
		-0.2f, 0.2f,  0.0f, 1.0f//oben Links
	};
	float rectAngle2[4 * 4] = {
		0.5f, 0.5f,	  width / spriteWidth, 1.0f,//oben rechts
		0.5f, -0.5f,  width / spriteWidth, (spriteHeight - height) / spriteHeight,//unten rechts
		-0.5f, -0.5f, 0.0f, (spriteHeight - height) / spriteHeight,//unten links
		-0.5f, 0.5f,  0.0f, 1.0f//oben Links
	};

	unsigned int indexArray[2 * 3] = {
		0, 1, 2,
		0, 2, 3
	};

	Buffer vertexBuffer(GL_ARRAY_BUFFER);
	vertexBuffer.bind();
	vertexBuffer.setBufferSizeF(16);
	vertexBuffer.addDataF(16, rectAngle);
	vertexBuffer.unbind();

	Buffer vertexBuffer2(GL_ARRAY_BUFFER);
	vertexBuffer2.bind();
	vertexBuffer2.setBufferSizeF(16);
	vertexBuffer2.addDataF(16, rectAngle2);
	vertexBuffer2.unbind();

	Buffer indexBuffer(GL_ELEMENT_ARRAY_BUFFER);
	indexBuffer.bind();
	indexBuffer.setBufferSizeUI(6);
	indexBuffer.addDataUI(6, indexArray);


	BufferArray bufferArray;
	bufferArray.addLayoutF(0, 2, 4, 0);
	bufferArray.addLayoutF(1, 2, 4, 2);
	bufferArray.aktivateAllLayouts();





	Shader shader("Resources/Shader.shader", "#defaultVertexShader", "#defaultFragmentShader");
	Shader shader2("Resources/Shader.shader", "#defaultVertexShader", "#defaultFragmentShader2");
	//indexBuffer.bind();
	shader.bind();
	shader.setUniform1i("ourTexture", 0);
	shader.activateTexture(GL_TEXTURE0);

	glm::vec2 render(0, width);
	int i = 0;
	int j = 0;
	float time = 0;
	while (!glfwWindowShouldClose(window))
	{



		if (j % 2 == 0) {

			vertexBuffer.bind();

		}
		else {
			vertexBuffer2.bind();
		}
		bufferArray.aktivateAllLayouts();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		//glUniform2f(glGetUniformLocation(shaderProgram, "additional"), render.x, (i % 8) * render.y);

		if (glfwGetTime() > time) {
			shader.setUniform2f("shift", (((i % 5)) * 63.0f + 1.0f) / spriteWidth, 0.0f);
			i++;
			time += 0.2f;
		}



		glfwSwapBuffers(window);


		glfwPollEvents();
		j++;
	}

	glfwTerminate();
	*/
	return 0;

}