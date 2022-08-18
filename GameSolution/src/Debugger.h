#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
     x;\
     ASSERT(GLLogCall(#x, __FILE__, __LINE__))


void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);


//Alle möglichen Werte sollen ausgegeben werden
template<typename X>
inline void LOG(X xValue) {
	std::cout << xValue << std::endl;
}

template<typename X, typename Y>
inline void LOG(X xValue, Y yValue) {
	std::cout << xValue << " " << yValue << std::endl;
}

template<typename X, typename Y, typename Z>
inline void LOG(X xValue, Y yValue, Z zValue) {
	std::cout << xValue << " " << yValue << " " << zValue << std::endl;
}

