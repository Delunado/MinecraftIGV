#include "pch.h"
#include "BoundingVolumeQuad.h"
#include "Bloque.h"


BoundingVolumeQuad::BoundingVolumeQuad()
{
}

BoundingVolumeQuad::BoundingVolumeQuad(Block* _block, POSITION _position): block(_block), position(_position), surface (Quad())
{
	
}


BoundingVolumeQuad::~BoundingVolumeQuad()
{
}

void BoundingVolumeQuad::DrawSurface()
{
	GLfloat aux[3] = {color[0] / 255.0f, color[1] / 255.0f, color[2] / 255.0f};
	surface.pintar_quad(block->GetSize());
	glColor3fv(aux);
}
