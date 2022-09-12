#include "Layer.h"

unsigned int Layer::heightFromWindow = 0;
unsigned int Layer::widthFromWindow = 0;

void Layer::setSizesFromWindow(WindowsWindow& window) {
	Layer::heightFromWindow = window.getWindowData().height;
	Layer::widthFromWindow = window.getWindowData().width;
	LOG(Layer::heightFromWindow, Layer::widthFromWindow);
}