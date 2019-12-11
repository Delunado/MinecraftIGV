#pragma once

#include <vector>
#include "TexturesManager.h"
#include "Grid3D.h"

class WorldManager
{
private:
	int height, width, depth;
	Grid3D worldGrid;
	TexturesManager texturesManager;
public:
	WorldManager(int height, int width, int depth);
	~WorldManager();

	void InitWorld();
	void DrawWorld();
};

