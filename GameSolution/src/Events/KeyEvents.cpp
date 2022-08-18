#include "KeyEvents.h"

//============keyPressKlass============//
KeyPress::KeyPress() {

}

KeyPress::KeyPress(const char* keyName, int key, int scanCode, int action, int mods) :
	keyName(keyName), key(key), scanCode(scanCode), action(action), mods(mods) {

	eventType = EventTypes::keyPressEvent;
}

KeyPress::~KeyPress() {

}


KeyRelease::KeyRelease() {
	//leer 
}


//============KeyRepeatKlass============//
KeyRepeat::KeyRepeat() {

}

KeyRepeat::KeyRepeat(const char* keyName, int key, int scanCode, int action, int mods) :
	keyName(keyName), key(key), scanCode(scanCode), action(action), mods(mods) {

	eventType = EventTypes::keyRepeatEvent;
}

KeyRepeat::~KeyRepeat() {

}



//============KeyReleaseKlass============//
KeyRelease::KeyRelease(const char* keyName, int key, int scanCode, int action, int mods) :
	keyName(keyName), key(key), scanCode(scanCode), action(action), mods(mods)
{

}

KeyRelease::~KeyRelease() {
	eventType = EventTypes::keyReleaseEvent;
}