#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../Debugger.h"
#include "../Events/Event.h"
#include "../Events/KeyEvents.h"
#include "../Events/MouseEvent.h"
#include "../Events/WindowEvent.h"

#include <functional>

class WindowsWindow {
private:

	struct WindowData {

		const char* titel;
		unsigned int height;
		unsigned int width;

		std::function<void(Event&)> applicationEventFunction;
	};

	GLFWwindow* window;
	WindowData windowData;


	bool init();

public:
	WindowsWindow();
	WindowsWindow(unsigned int height, unsigned int width, const char* titel);
	~WindowsWindow();

	void createWindow();
	void updateWindow();
	void setApplicationEventFunction(std::function<void(Event&)> applicationEventFunction);

	void inline closeWindow() { glfwWindowShouldClose(window); }

};