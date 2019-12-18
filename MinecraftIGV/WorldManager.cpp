#include "pch.h"
#include "WorldManager.h"
#include <iostream>

WorldManager::WorldManager(int _width, int _height, int _depth): height(_height), width(_width), depth(_depth),
																 worldGrid(width, height, depth), texturesManager()
{}


WorldManager::~WorldManager()
{}

void WorldManager::InitWorld() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			for (int z = 0; z < depth; z++) {
				worldGrid.GetBlock(x, y, z)->SetId(0);
			}
		}
	}
}

void WorldManager::DrawWorld() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			for (int z = 0; z < depth; z++) {
				//std::cout << "X: " << worldGrid.GetBlock(i, j, k)->xMundo << " Y : " << worldGrid.GetBlock(i, j, k)->yMundo << " Z: " << worldGrid.GetBlock(i, j, k)->zMundo << std::endl;
				worldGrid.GetBlock(x, y, z)->DrawBlock();
			}
		}
	}
}
