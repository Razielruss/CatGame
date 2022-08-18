#pragma once
#include "Event.h"

class KeyPress : public Event {

private:
	std::string keyName;
	int key;
	int scanCode;
	int action;
	int mods;

public:

	KeyPress();
	KeyPress(const char* keyName, int key, int scanCode, int action, int mods);
	~KeyPress();

	inline int getKey() {
		return key;
	}

	inline std::string getKeyName() {
		return keyName;
	}

	inline int getScanCode() {
		return scanCode;
	}

	inline unsigned int getEventType() override {
		return eventType;
	}

#if _DEBUG
	virtual inline void printKeyInfo() {
		std::cout << "key: " << key << " scanCode: " << scanCode << " keyName: " << keyName << std::endl;
	}
#endif

};

class KeyRepeat : public Event {

private:
	std::string keyName;
	int key;
	int scanCode;
	int action;
	int mods;

public:

	KeyRepeat();
	KeyRepeat(const char* keyName, int key, int scanCode, int action, int mods);
	~KeyRepeat();


	inline int getKey() {
		return key;
	}

	inline std::string getKeyName() {
		return keyName;
	}

	inline int getScanCode() {
		return scanCode;
	}

	inline unsigned int getEventType() override {
		return eventType;
	}

#if _DEBUG
	virtual inline void printKeyInfo() {
		std::cout << "key: " << key << " scanCode: " << scanCode << " keyName: " << keyName << std::endl;
	}
#endif
};

class KeyRelease : public Event {

private:
	std::string keyName;
	int key;
	int scanCode;
	int action;
	int mods;

public:

	KeyRelease();
	KeyRelease(const char* keyName, int key, int scanCode, int action, int mods);
	~KeyRelease();


	inline int getKey() {
		return key;
	}

	inline std::string getKeyName() {
		return keyName;
	}

	inline int getScanCode() {
		return scanCode;
	}

	inline unsigned int getEventType() override {
		return eventType;
	}

#if _DEBUG
	virtual inline void printKeyInfo() {
		std::cout << "key: " << key << " scanCode: " << scanCode << " keyName: " << keyName << std::endl;
	}
#endif
};