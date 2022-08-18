#pragma once
#include <string>

#if _DEBUG
#include <iostream>
#endif
class Event {

protected:

	unsigned int eventType;

public:
	enum EventTypes {
		windowCloseEvent = 0,
		windowResizeEvent = 1,
		keyPressEvent = 2,
		keyRepeatEvent = 3,
		keyReleaseEvent = 4
	};
	virtual inline unsigned int getEventType() = 0;
	virtual inline void printKeyInfo() = 0;
};