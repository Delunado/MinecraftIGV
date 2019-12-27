#ifndef __BLOQUE
#define __BLOQUE

#pragma once
#include "pch.h"
#include <cstdlib>
#include <stdio.h>

class BoundingVolumeQuad;

#include "igvTextura.h"
#include "TextureTypes.h"
#include "Quad.h"
#include <vector>
#include <iostream>

class Bloque
{
public:
	Bloque(TEXTURES textureType, int _x, int _y, int _z);
	~Bloque();

	int x, y, z;
	float xMundo, yMundo, zMundo;

	void DrawBlock();
	void DrawBlockBV();

	void SetTextureType(TEXTURES _textureType) {
		textureType = _textureType;
	}

	void SetTexture(igvTextura* _texture) {
		texture = _texture;
	}

	TEXTURES GetTextureType() {
		return textureType;
	}

	float GetSize() {
		return size;
	}

	std::vector<BoundingVolumeQuad*> GetBVArray() {
		return BVarray;
	}

	void InitBV();

	void SetPosition(int _x, int _y, int _z) {
		x = _x;
		y = _y;
		z = _z;
		xMundo = (float)_x * size;
		yMundo = (float)_y * size;
		zMundo = (float)_z * size;
	}

	/*
0 = Bottom Face
1 = Top Face
2 = Front Face
3 = Back Face
4 = Left Face
5 = Right Face
*/
	std::vector<BoundingVolumeQuad*> BVarray;


private: 
	const float size = 1.0f;

	Quad* side;

	igvTextura* texture;
	TEXTURES textureType;
};

#endif
