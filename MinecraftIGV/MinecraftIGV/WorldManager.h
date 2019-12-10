#pragma once

#include <vector>
#include "Bloque.h"

class WorldManager
{
private:
	Bloque* worldMatrix[5][5][5];
public:
	WorldManager();
	~WorldManager();

	void InitWorld(int height, int width, int depth);
	void DrawWorld();
};

