#pragma once
#include <vector>
#include "../../utils/Debugger.h"

//Struktur um das LAyout zu speichern
struct Layout {
	unsigned int index;					//Index der ersten Werte des Strides
	int size;							//Anzahl der Werte die sich in dem Index befinden
	int stride;							//die Größe eines Vertexes
	int offset;
};

class BufferArray {
private:
	unsigned int bufferID;
	std::vector<Layout>bufferLayouts;	//Speichert die eingestellten Layouts

public:
	BufferArray();
	~BufferArray();

	template<typename T>
	void addLayout(unsigned int index, int size, int stride, int offset) {
		Layout layout;
		layout.index = index;
		layout.size = size;
		layout.stride = stride * sizeof(T);
		layout.offset = offset * sizeof(T);

		bufferLayouts.push_back(layout);
	}

	//Bestimmtes Layout wird aktiviert
	void aktivateLayout(unsigned int index);

	//Alle definierten Layouts werden aktiviert
	void aktivateAllLayouts();
};