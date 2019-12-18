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
	WorldManager(int _width, int _height, int _depth);
	~WorldManager();

	void InitWorld();
	void DrawWorld();
};

