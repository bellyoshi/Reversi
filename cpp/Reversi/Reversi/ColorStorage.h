#pragma once
#include "Disc.h"

template<typename T> class ColorStorage
{
private:
	T data[3] = { 0 };
public:
	T& operator[](Color color) {
		return data[color + 1];
	}
	const T& operator[](Color color)const {
		return data[color + 1];
	}
};

