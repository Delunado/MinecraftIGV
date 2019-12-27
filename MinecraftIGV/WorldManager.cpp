#include "pch.h"
#include "WorldManager.h"
#include <iostream>

WorldManager::WorldManager(int _width, int _height, int _depth): height(_height), width(_width), depth(_depth), 
											    worldGrid(width, height, depth), 
												texturesManager()
{}


WorldManager::~WorldManager()
{}

void WorldManager::SetSelectionController(SelectionController* _selectionController)
{
	selectionController = _selectionController;
}

void WorldManager::SetTextureToBlock(TEXTURES textureType, Bloque* block)
{
	block->SetTextureType(textureType);
	texturesManager.SetTextureToBlock(block);
}

void WorldManager::InitWorld() {
	texturesManager.LoadTextures(); //First we load the textures

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			for (int z = 0; z < depth; z++) {
				Bloque* actualBlock = worldGrid.GetBlock(x, y, z);
				selectionController->AddBoundingVolumes(actualBlock);
	/*			if (rand() % 2 == 0)*/
					SetTextureToBlock(TEXTURES::NONE, actualBlock);
				//else if (rand() % 2 == 0)
				//	actualBlock->SetTextureType(TEXTURES::STONE);
				//else
				//	actualBlock->SetTextureType(TEXTURES::NONE);
			}
		}
	}

	SetTextureToBlock(TEXTURES::DIRT, worldGrid.GetBlock(2, 2, 2));
}

void WorldManager::DrawWorld() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			for (int z = 0; z < depth; z++) {
				//std::cout << "X: " << worldGrid.GetBlock(i, j, k)->xMundo << " Y : " << worldGrid.GetBlock(i, j, k)->yMundo << " Z: " << worldGrid.GetBlock(i, j, k)->zMundo << std::endl;
				Bloque* actualBlock = worldGrid.GetBlock(x, y, z);
				actualBlock->DrawBlock();
			}
		}
	}
}

void WorldManager::DrawWorldBV()
{
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			for (int z = 0; z < depth; z++) {
				//std::cout << "X: " << worldGrid.GetBlock(i, j, k)->xMundo << " Y : " << worldGrid.GetBlock(i, j, k)->yMundo << " Z: " << worldGrid.GetBlock(i, j, k)->zMundo << std::endl;
				Bloque* actualBlock = worldGrid.GetBlock(x, y, z);
				actualBlock->DrawBlockBV();
			}
		}
	}
}

void WorldManager::CreateBlock(Bloque* block, POSITION _position, TEXTURES textureType)
{
	switch (_position)
	{
	case POSITION::FRONT_FACE:
		if ((block->z + 1) < depth) //Si hay espacio en la matriz para poner
			if (worldGrid.GetBlock(block->x, block->y, (block->z + 1))->GetTextureType() == TEXTURES::NONE)
				SetTextureToBlock(textureType, worldGrid.GetBlock(block->x, block->y, (block->z + 1)));
		break;
	case POSITION::BACK_FACE:
		if ((block->z - 1) >= 0)
			if (worldGrid.GetBlock(block->x, block->y, (block->z - 1))->GetTextureType() == TEXTURES::NONE)
				SetTextureToBlock(textureType, worldGrid.GetBlock(block->x, block->y, (block->z - 1)));
		break;
	case POSITION::TOP_FACE:
		if ((block->y - 1) >= 0)
			if (worldGrid.GetBlock(block->x, (block->y - 1), block->z)->GetTextureType() == TEXTURES::NONE)
				SetTextureToBlock(textureType, worldGrid.GetBlock(block->x, (block->y - 1), block->z));
		break;
	case POSITION::BOTTOM_FACE:
		if ((block->y + 1) < height)
			if (worldGrid.GetBlock(block->x, (block->y + 1), block->z)->GetTextureType() == TEXTURES::NONE)
				SetTextureToBlock(textureType, worldGrid.GetBlock(block->x, (block->y + 1), block->z));
		break;
	case POSITION::LEFT_FACE:
		if ((block->x - 1) >= 0)
			if (worldGrid.GetBlock((block->x - 1), block->y, block->z)->GetTextureType() == TEXTURES::NONE)
				SetTextureToBlock(textureType, worldGrid.GetBlock((block->x - 1), block->y, block->z));
		break;
	case POSITION::RIGHT_FACE:
		if ((block->x + 1) < width)
			if (worldGrid.GetBlock((block->x + 1), block->y, block->z)->GetTextureType() == TEXTURES::NONE)
				SetTextureToBlock(textureType, worldGrid.GetBlock((block->x + 1), block->y, block->z));
		break;
	default:
		break;
	}
}

void WorldManager::EraseBlock(Bloque* block)
{
	block->SetTextureType(TEXTURES::NONE);
}
