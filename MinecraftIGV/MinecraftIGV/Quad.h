#include "pch.h"
#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"
#include "igvFuenteLuz.h"
#include "igvMaterial.h"
#include "igvTextura.h"


#ifndef __QUAD
#define __QUAD

class Quad
{
public:
	Quad();
	~Quad();

	void pintar_quad(float div_x, float div_z);	
};

#endif
