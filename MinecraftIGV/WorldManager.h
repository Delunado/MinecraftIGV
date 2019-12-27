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
public:
	WorldManager(int _width, int _height, int _depth);
	~WorldManager();

	void SetSelectionController(SelectionController* _selectionController);

	void SetTextureToBlock(TEXTURES textureType, Bloque* block);

	void InitWorld();
	void DrawWorld();
	void DrawWorldBV();

	void CreateBlock(Bloque* block, POSITION _position, TEXTURES textureType);
	void EraseBlock(Bloque* block);
};

