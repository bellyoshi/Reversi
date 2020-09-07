#pragma once
template<typename T, size_t sizeX, size_t sizeY, size_t sizeZ>
class Cube
{
	T* data;
public:
	int index(int x, int y, int z) {
		return z * (sizeY * sizeX) + y * sizeX + x;
	}
	Cube() {
		data = new T[sizeX * sizeY * sizeZ];
	}
	~Cube()
	{
		delete[] data;
	}
	T& Cells(int x, int y, int z) {
		return data[index(x, y, z)];
	}
};

