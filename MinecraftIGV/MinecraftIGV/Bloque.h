#include "pch.h"
#include <cstdlib>
#include <stdio.h>

#include "Quad.h"

#ifndef __BLOQUE
#define __BLOQUE
class Bloque
{
public:
	Bloque(float _x, float _y, float _z);
	~Bloque();

	float x, y, z;
	float xMundo, yMundo, zMundo;

	void DrawBlock();

private: 
	const float size = 1.0f;

	Quad* side;
};

#endif
