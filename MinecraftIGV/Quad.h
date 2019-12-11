#include "pch.h"
#include <cstdlib>
#include <stdio.h>

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#ifndef __QUAD
#define __QUAD

class Quad
{
public:
	Quad();
	~Quad();

	void pintar_quad(float tam, float div_x = 50.0f, float div_z = 50.0f);	
};

#endif
