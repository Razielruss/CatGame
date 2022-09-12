#pragma once
#include "Windows/WindowsWindow.h"
#include "Events/Event.h"
#include <functional>
#include "Layers/CharakterLayer.h"
#include "Layers/Layer.h"
#include <vector>

using namespace std::placeholders;
class Application {

private:
	bool run;
	WindowsWindow* window;
	std::vector<Layer*> layerStack;

public:
	Application();
	~Application();

	void runApplication();
	void onEvent(Event& event);
	void closeWindow(Event& event);
	void initLayer();

};