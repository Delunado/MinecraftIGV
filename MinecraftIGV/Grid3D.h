#pragma once
#include <vector>

#include "Bloque.h"

class Grid3D
{
private:
	int height, width, depth;
	std::vector<Bloque*>* world;

public:
	Grid3D(int _width, int _height, int _depth);
	~Grid3D();

	Bloque* GetBlock(int x, int y, int z);
};

