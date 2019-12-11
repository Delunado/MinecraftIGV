#include "pch.h"
#include <cstdlib>
#include <stdio.h>

#include "Quad.h"

#ifndef __BLOQUE
#define __BLOQUE
class Bloque
{
public:
	Bloque(int id, int _x, int _y, int _z);
	~Bloque();

	int x, y, z;
	float xMundo, yMundo, zMundo;

	void DrawBlock();

	int GetId() {
		return id;
	}

	void SetId(int _id) {
		id = _id;
	}

private: 
	const float size = 1.0f;
	int id;

	Quad* side;
};

#endif
