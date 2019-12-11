#include "pch.h"
#include "TexturesManager.h"

TexturesManager::~TexturesManager()
{
}

void TexturesManager::LoadTextures()
{
	textureVector = new igvTextura*[3];
	igvTextura textureBlock("Block.bmp");
	igvTextura textureStone("stone.bmp");

	textureVector[0] = &textureBlock;
	textureVector[1] = &textureStone;
}

igvTextura* TexturesManager::GetTexture(TEXTURES texture) {
	igvTextura* textura = NULL;

	switch (texture)
	{
	case TEXTURES::DIRT:
		textura = textureVector[0];
		break;
	case TEXTURES::STONE:
		textura = textureVector[1];
		break;
	}

	return textura;
}