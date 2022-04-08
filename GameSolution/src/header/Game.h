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

//temporär kommt in die Kamera Klasse
static glm::vec3 cameraPos;
static glm::vec3 cameraFront;
static glm::vec3 cameraUp;

static float yaw, pitch;

static glm::mat4 view;

static float lastX, lastY;
static bool firstMouse;
static float deltaTime = 0.0f, lastTime = 0.0f;

static Debugger debugger;

class Game {
private:
	Shader* shader;
	Buffer* vertexBuffer, * indexBuffer;
	BufferArray* arrayBuffer;
	Sprite* charakterSprite;
	Charakter* charakter;

	GLFWwindow* window;
	float windowHeight;
	float windowWidth;

	bool run;

	bool initOpenGL();
	bool initGame();
	static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);


public:

	Game();
	~Game();
	void process();
	void cameraTest();
	//TODO load first map => buffer weiter befüllen und karte laden
	//void loadMap();
};