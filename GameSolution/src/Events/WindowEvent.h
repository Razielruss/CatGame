#pragma once
#include "Event.h"

class WindowCloseEvent : public Event {

public:

	WindowCloseEvent();
	~WindowCloseEvent();

	virtual inline unsigned int getEventType() {
		return eventType;
	}
#if _DEBUG
	virtual inline void printKeyInfo() {
		std::cout << "Window Close Event" << std::endl;
	}
#endif
};

class WindowResize : public Event {

};