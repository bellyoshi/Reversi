#pragma once
#include <array>

template<typename T,size_t sizeX, size_t sizeY>
class Grid
{
	T* data;
public:
	int index(int x, int y) {
		return y * sizeX + x;
	}
	Grid() {
		data = new T[sizeX * sizeY];
	}
	~Grid()
	{
		delete[] data;
	}
	T& Cells(int x, int y) {
		return data[index(x, y)];
	}
};

