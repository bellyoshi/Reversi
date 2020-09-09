#pragma once
#include <array>
#include <initializer_list>
#include <algorithm>

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
	Grid(std::initializer_list<T> init) : Grid() {
		std::copy(init.begin(), init.end(), data);
	}
	~Grid()
	{
		delete[] data;
	}
	T& Cells(int x, int y) {
		return data[index(x, y)];
	}
	
	T& operator[](int i) {
		return data[i];
	}
	const T& operator[](int i)const {
		return data[i];
	}

};

