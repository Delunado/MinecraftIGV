#include "pch.h"
#include "WorldManager.h"

WorldManager::WorldManager(int height, int width, int depth): worldGrid(height, width, depth), texturesManager()
{}


WorldManager::~WorldManager()
{}

void WorldManager::InitWorld() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			for (int k = 0; k < depth; k++) {
				worldGrid.GetBlock(i, j, k)->SetId(0);
			}
		}
	}
}

void WorldManager::DrawWorld() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			for (int k = 0; k < depth; k++) {
				worldGrid.GetBlock(i, j, k)->DrawBlock();
			}
		}
	}
}
