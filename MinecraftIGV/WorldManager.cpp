#include "pch.h"
#include "WorldManager.h"


WorldManager::WorldManager()
{
	InitWorld(1, 1, 1);
}


WorldManager::~WorldManager()
{
}

void WorldManager::InitWorld(int height, int width, int depth) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			for (int k = 0; k < depth; k++) {
				worldMatrix[i][j][k] = new Bloque((float)i, (float)j, (float)k);
			}
		}
	}
}

void WorldManager::DrawWorld() {
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			for (int k = 0; k < 1; k++)
				worldMatrix[i][k][j]->DrawBlock();
		}
	}
}
