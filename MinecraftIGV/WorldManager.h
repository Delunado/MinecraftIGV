#pragma once

#include <vector>
#include "Grid3D.h"
#include "Bloque.h"

class WorldManager
{
private:
	int height, width, depth;
	Grid3D<Bloque*> worldGrid;
public:
	WorldManager();
	~WorldManager();

	void InitWorld(int height, int width, int depth);
	void DrawWorld();
};

