#include "Application.h"

Application::Application() {
	run = true;
	window = new WindowsWindow(1024, 768, "Cat Game");
	window->setApplicationEventFunction(std::bind(&Application::onEvent, this, _1));
}

Application::~Application() {
	delete window;
}

void Application::runApplication() {

	while (run) {

		window->updateWindow();

	}
}

void Application::onEvent(Event& e) {


	switch (e.getEventType()) {

	case Event::EventTypes::windowCloseEvent:
		closeWindow(e);
		break;
	}

}

void Application::closeWindow(Event& e) {
	run = false;
	window->closeWindow();
}