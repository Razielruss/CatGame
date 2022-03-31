#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Shader.h"
#include "Buffer.h"
#include "BufferArray.h"
#include "Sprite.h"
#include "Charakter.h"
#include "Debugger.h"

class Game {
private:
	Shader* shader;
	Buffer* vertexBuffer, * indexBuffer;
	BufferArray* arrayBuffer;
	Sprite* charakterSprite;
	Charakter* charakter;

	GLFWwindow* window;
	int windowHeight;
	int windowWidth;

	bool run;

	bool initOpenGL();
	bool initGame();
	static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);

public:

	Game();
	~Game();
	void process();

	//TODO load first map => buffer weiter befüllen und karte laden
	//void loadMap();
};