#pragma once
#include "Windows/WindowsWindow.h"
#include "Events/Event.h"
#include <functional>

//später bearbeiten
#include "Renderer/BatchRenderer2D.h"
#include "Renderer/OpenGL/Shader.h"

//kann später entfernt werden
#include "Renderer/Charakter.h"

using namespace std::placeholders;
class Application {

private:
	bool run;
	WindowsWindow* window;

public:
	Application();
	~Application();

	void runApplication();
	void onEvent(Event& event);
	void closeWindow(Event& event);

};