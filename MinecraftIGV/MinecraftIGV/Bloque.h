#include "pch.h"
#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"
#include "igvFuenteLuz.h"
#include "igvMaterial.h"
#include "igvTextura.h"
#include "Quad.h"

class Bloque
{
public:
	Bloque(float _x, float _y, float _z);
	~Bloque();

	float x, y, z;

	void DrawBlock();

private: 
	Quad* sides[6];
};

