#include "pch.h"
#include "WorldManager.h"
#include <iostream>

WorldManager::WorldManager(int _width, int _height, int _depth): height(_height), width(_width), depth(_depth), 
											    worldGrid(width, height, depth), 
												texturesManager()
{
	selectedTextureType = TEXTURES::STONE;
}


WorldManager::~WorldManager()
{}

int WorldManager::GetWorldHeight()
{
	return height;
}

int WorldManager::GetWorldWidth()
{
	return width;
}

int WorldManager::GetWorldDepth()
{
	return depth;
}

void WorldManager::SetSelectionController(SelectionController* _selectionController)
{
	selectionController = _selectionController;
}

void WorldManager::SetSelectedTextureType(TEXTURES textureType)
{
	selectedTextureType = textureType;
}

void WorldManager::SetTextureToBlock(TEXTURES textureType, Block* block)
{
	block->SetTextureType(textureType);
	texturesManager.SetTextureToBlock(block);
}

void WorldManager::InitWorld() {
	texturesManager.LoadTextures(); //First we load the textures

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			for (int z = 0; z < depth; z++) {
				Block* actualBlock = worldGrid.GetBlock(x, y, z);
				selectionController->AddBoundingVolumes(actualBlock);
			}
		}
	}

	for (int x = 0; x < width; x++) {
		for (int z = 0; z < depth; z++)
			SetTextureToBlock(TEXTURES::DIRT, worldGrid.GetBlock(x, 0, z));
	}

}

void WorldManager::ResetWorld() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			for (int z = 0; z < depth; z++) {
				Block* actualBlock = worldGrid.GetBlock(x, y, z);
				if (y == 0) {
					SetTextureToBlock(TEXTURES::DIRT, actualBlock);
				}
				else {
					SetTextureToBlock(TEXTURES::NONE, actualBlock);
				}
			}
		}
	}
}

void WorldManager::DrawWorld() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			for (int z = 0; z < depth; z++) {
				Block* actualBlock = worldGrid.GetBlock(x, y, z);
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
				Block* actualBlock = worldGrid.GetBlock(x, y, z);
				actualBlock->DrawBlockBV();
			}
		}
	}
}

/**
Crea un bloque respecto a la posición indicada en el bloque indicado.
*/
void WorldManager::CreateBlock(Block* block, POSITION _position)
{
	switch (_position)
	{
	case POSITION::FRONT_FACE:
		if ((block->z + 1) < depth)
			if (worldGrid.GetBlock(block->x, block->y, (block->z + 1))->GetTextureType() == TEXTURES::NONE)
				SetTextureToBlock(selectedTextureType, worldGrid.GetBlock(block->x, block->y, (block->z + 1)));
		break;
	case POSITION::BACK_FACE:
		if ((block->z - 1) >= 0)
			if (worldGrid.GetBlock(block->x, block->y, (block->z - 1))->GetTextureType() == TEXTURES::NONE)
				SetTextureToBlock(selectedTextureType, worldGrid.GetBlock(block->x, block->y, (block->z - 1)));
		break;
	case POSITION::BOTTOM_FACE:
		if ((block->y - 1) >= 0)
			if (worldGrid.GetBlock(block->x, (block->y - 1), block->z)->GetTextureType() == TEXTURES::NONE)
				SetTextureToBlock(selectedTextureType, worldGrid.GetBlock(block->x, (block->y - 1), block->z));
		break;
	case POSITION::TOP_FACE:
		if ((block->y + 1) < height)
			if (worldGrid.GetBlock(block->x, (block->y + 1), block->z)->GetTextureType() == TEXTURES::NONE)
				SetTextureToBlock(selectedTextureType, worldGrid.GetBlock(block->x, (block->y + 1), block->z));
		break;
	case POSITION::LEFT_FACE:
		if ((block->x - 1) >= 0)
			if (worldGrid.GetBlock((block->x - 1), block->y, block->z)->GetTextureType() == TEXTURES::NONE)
				SetTextureToBlock(selectedTextureType, worldGrid.GetBlock((block->x - 1), block->y, block->z));
		break;
	case POSITION::RIGHT_FACE:
		if ((block->x + 1) < width)
			if (worldGrid.GetBlock((block->x + 1), block->y, block->z)->GetTextureType() == TEXTURES::NONE)
				SetTextureToBlock(selectedTextureType, worldGrid.GetBlock((block->x + 1), block->y, block->z));
		break;
	default:
		break;
	}
}

void WorldManager::EraseBlock(Block* block)
{
	block->SetTextureType(TEXTURES::NONE);
}
