#include "pch.h"
#include <cstdlib>
#include <stdio.h>

#include "igvTextura.h"

#ifndef __TEXTURESMANAGER
#define __TEXTURESMANAGER

enum TEXTURES {DIRT, STONE};

class TexturesManager
{
private:
	igvTextura** textureVector;
public:
	//TexturesManager();
	~TexturesManager();

    igvTextura* GetTexture(TEXTURES texture);	
	void LoadTextures();
};

#endif
