#pragma once

#include <vector>
#include "Bloque.h"

class WorldManager
{
private:
	std::vector<std::vector<std::vector<Bloque>>> worldMatrix;
public:
	WorldManager();
	~WorldManager();

	void InitWorld(int height, int width, int depth);
};

