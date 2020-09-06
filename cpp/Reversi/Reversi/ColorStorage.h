#pragma once
#include "Disc.h"

template<typename T> class ColorStorage
{
private:
	T data[3] = { 0 };
public:
	void Clear() {
		for (int i = 0; sizeof(data) / sizeof(data[0]); i++) {
			data[i] = 0;
		}
	}
	T& operator[](Color color) {
		return data[color + 1];
	}
	const T& operator[](Color color)const {
		return data[color + 1];
	}
};

