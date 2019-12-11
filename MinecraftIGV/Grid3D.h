#pragma once
#include <vector>

#include "Bloque.h"

typedef std::vector<std::vector<std::vector<Bloque*>>> matrix3D;

class Grid3D
{
private:
	int height, width, depth;
	matrix3D* world;

public:
	Grid3D(int height, int width, int depth);
	~Grid3D();

	Bloque* GetBlock(int x, int y, int z);
};

