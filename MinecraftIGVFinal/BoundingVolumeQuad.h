#ifndef __BOUNDINGVOLUMEQUAD
#define __BOUNDINGVOLUMEQUAD

#pragma once

class Block;

#include "Quad.h"
#include "TextureTypes.h"
#include "POSITION.h"
#include <iostream>

class BoundingVolumeQuad
{
private:
	Quad surface;
	Block* block;
	GLint color[3]; //Puntero a vector de tamaño 3 para guardar un color
	POSITION position;
public:
	BoundingVolumeQuad();
	BoundingVolumeQuad(Block* _block, POSITION _position);
	~BoundingVolumeQuad();

	void DrawSurface();

	POSITION GetPosition() {
		return position;
	}

	void SetColor(GLint _color[3]) {
		color[0] = _color[0];
		color[1] = _color[1];
		color[2] = _color[2];
	}

	GLint* GetColor() {
		return color;
	}

	Block* GetBlock() {
		return block;
	}
};

#endif

