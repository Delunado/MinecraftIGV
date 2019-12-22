#include "pch.h"
#include <cstdlib>
#include <stdio.h>

#include "Quad.h"
#include "igvTextura.h"
#include "TextureTypes.h"
#include <iostream>

#ifndef __BLOQUE
#define __BLOQUE
class Bloque
{
public:
	Bloque(TEXTURES textureType, int _x, int _y, int _z);
	~Bloque();

	int x, y, z;
	float xMundo, yMundo, zMundo;

	void DrawBlock();

	int GetId() {
		return id;
	}

	void SetId(int _id);

	void SetTextureType(TEXTURES _textureType) {
		textureType = _textureType;
	}

	void SetTexture(igvTextura* _texture) {
		texture = _texture;
	}

	TEXTURES GetTextureType() {
		return textureType;
	}

	void SetPosition(int _x, int _y, int _z) {
		x = _x;
		y = _y;
		z = _z;
		xMundo = (float)_x * size;
		yMundo = (float)_y * size;
		zMundo = (float)_z * size;
	}


private: 
	const float size = 1.0f;
	int id;

	Quad* side;
	igvTextura* texture;
	TEXTURES textureType;
};

#endif
