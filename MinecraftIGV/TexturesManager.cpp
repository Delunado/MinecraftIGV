#include "pch.h"
#include "TexturesManager.h"
#include "TextureTypes.h"


TexturesManager::TexturesManager()
{
	
}

TexturesManager::~TexturesManager()
{
}

void TexturesManager::LoadTextures()
{
	igvTextura* textureBlock = new igvTextura("Block.bmp");
	igvTextura* textureStone = new igvTextura("stone.bmp");

	textureVector[0] = textureBlock;
	textureVector[1] = textureStone;
}

void TexturesManager::SetTextureToBlock(Bloque* block)
{
	block->SetTexture(GetTexture(block->GetTextureType()));
}

igvTextura* TexturesManager::GetTexture(TEXTURES texture) {
	igvTextura* auxTexture = NULL;

	switch (texture)
	{
	case TEXTURES::DIRT:
		auxTexture = textureVector[0];
		break;
	case TEXTURES::STONE:
		auxTexture = textureVector[1];
		break;
	}

	return auxTexture;
}