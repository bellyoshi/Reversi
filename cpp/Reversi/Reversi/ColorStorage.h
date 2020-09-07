#pragma once
#include "Disc.h"
#include <array>

template<typename T> class ColorStorage
{
private:
	std::array<T,3> data = { 0 };
public:
	void Clear() {
		for (T &var : data) {
			var = 0;
		}
	}
	T& operator[](Color color) {
		return data[color + 1];
	}
	const T& operator[](Color color)const {
		return data[color + 1];
	}
};

