#pragma once

#include <vector>
#include "TexturesManager.h"
#include "SelectionController.h"
#include "Grid3D.h"
#include "POSITION.h"

class WorldManager
{
private:
	int height, width, depth;
	Grid3D worldGrid;
	TexturesManager texturesManager;
	SelectionController* selectionController;

	TEXTURES selectedTextureType; //La textura seleccionada actualmente
public:
	WorldManager(int _width, int _height, int _depth);
	~WorldManager();

	int GetWorldHeight();
	int GetWorldWidth();
	int GetWorldDepth();

	void SetSelectionController(SelectionController* _selectionController);

	void SetSelectedTextureType(TEXTURES textureType);
	void SetTextureToBlock(TEXTURES textureType, Block* block);

	void InitWorld();
	void ResetWorld();
	void DrawWorld();
	void DrawWorldBV();

	void CreateBlock(Block* block, POSITION _position);
	void EraseBlock(Block* block);
};

