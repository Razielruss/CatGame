#include "WindowsWindow.h"

// Private Funktion
bool WindowsWindow::init() {

	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(windowData.width, windowData.height, windowData.titel, NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		LOG("ERROR");
	}

	glfwSetWindowSizeCallback(window, [](GLFWwindow* windowAsParameter, int width, int height)
		{
			LOG("resize");
		});

	glfwSetWindowCloseCallback(window, [](GLFWwindow* windowAsParameter)
		{
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(windowAsParameter);
			WindowCloseEvent windowCloseEvent;
			windowData.applicationEventFunction(windowCloseEvent);
		});

	glfwSetKeyCallback(window, [](GLFWwindow* windowAsParameter, int key, int scanCode, int action, int mods)
		{
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(windowAsParameter);


			switch (action)
			{
			case GLFW_PRESS:
			{
				if (glfwGetKeyName(key, scanCode) != NULL) {
					KeyPress keyPress(glfwGetKeyName(key, scanCode), key, scanCode, action, mods);
					keyPress.printKeyInfo();
					windowData.applicationEventFunction(keyPress);
				}
				break;
			}
			case GLFW_RELEASE:
			{
				if (glfwGetKeyName(key, scanCode) != NULL) {
					LOG("KEY RELEASE", glfwGetKeyName(key, scanCode));
				}
				break;
			}
			case GLFW_REPEAT:
			{
				if (glfwGetKeyName(key, scanCode) != NULL) {
					LOG("KEY REPEAT", glfwGetKeyName(key, scanCode));
				}
			}
			}
		});
	return true;
}




//Public functionen
WindowsWindow::WindowsWindow() {
	windowData.width = 1024;
	windowData.height = 768;
	windowData.titel = "Default Window";

	init();


}

WindowsWindow::WindowsWindow(unsigned int width, unsigned int height, const char* titel) {

	windowData.height = height;
	windowData.width = width;
	windowData.titel = titel;

	if (!init()) {
		LOG("ERROR: windo initialisierung");
	}

	glfwSetWindowUserPointer(window, &windowData);


}

WindowsWindow::~WindowsWindow() {

}

void WindowsWindow::createWindow() {

}

void WindowsWindow::updateWindow() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void WindowsWindow::setApplicationEventFunction(std::function<void(Event&)> applicationEventFunction) {
	windowData.applicationEventFunction = applicationEventFunction;
}

