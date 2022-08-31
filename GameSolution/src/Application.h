#pragma once
#include "Windows/WindowsWindow.h"
#include "Events/Event.h"
#include <functional>
#include "Layers/CharakterLayer.h"

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