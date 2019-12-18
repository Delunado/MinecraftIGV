#include "pch.h"
#include <cstdlib>
#include <stdio.h>

#include <array> 
#include "igvTextura.h"
#include "Bloque.h"

#ifndef __TEXTURESMANAGER
#define __TEXTURESMANAGER

class TexturesManager
{
private:
	std::array<igvTextura*, 2> textureVector; //2 is the number of elements of the array
public:
	TexturesManager();
	~TexturesManager();

    igvTextura* GetTexture(TEXTURES texture);	
	void LoadTextures();
	void SetTextureToBlock(Bloque* block);
};

#endif
