#include "pch.h"
#include "BoundingVolumeQuad.h"
#include "Bloque.h"
#include <iostream>

Bloque::Bloque(TEXTURES _textureType, int _x, int _y, int _z) : textureType(_textureType), x(_x), y(_y), z(_z), side(new Quad()), BVarray()
{
	xMundo = (float)_x * size;
	yMundo = (float)_y * size;
	zMundo = (float)_z * size;
}

Bloque::~Bloque()
{
}

void Bloque::InitBV() {
	for (int i = 0; i < 6; i++) {
		BVarray.push_back(new BoundingVolumeQuad(this, (POSITION)i));
	}
}

void Bloque::DrawBlock() {
	if (textureType == TEXTURES::NONE)
		return;

	texture->aplicar();

	glPushMatrix();

	glTranslatef(xMundo, yMundo, zMundo);

	//Bottom Face
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(0, 1.0f, 0.0f, 0.0f);
	side->pintar_quad(size);
	glPopMatrix();

	//Back Face
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	side->pintar_quad(size);
	glPopMatrix();

	//Top Face
	glPushMatrix();
	glTranslatef(0, size, 0);
	glRotatef(0, 1.0f, 0.0f, 0.0f);
	side->pintar_quad(size);
	glPopMatrix();

	//Front Face
	glPushMatrix();
	glTranslatef(0, 0, size);
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	side->pintar_quad(size);

	glPopMatrix();

	//Left Face
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 0.0f, 0.0f, 1.0f);
	side->pintar_quad(size);

	glPopMatrix();

	//Right Face
	glPushMatrix();
	glTranslatef(size, 0, 0);
	glRotatef(90, 0.0f, 0.0f, 1.0f);
	side->pintar_quad(size);

	glPopMatrix();

	glPopMatrix();
}

void Bloque::DrawBlockBV()
{
	if (textureType == TEXTURES::NONE)
		return;

	glPushMatrix();

	glTranslatef(xMundo, yMundo, zMundo);

	//Bottom Face
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(0, 1.0f, 0.0f, 0.0f);
	BVarray[0]->DrawSurface();
	glPopMatrix();

	//Back Face
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	BVarray.operator[](3)->DrawSurface();
	glPopMatrix();

	//Top Face
	glPushMatrix();
	glTranslatef(0, size, 0);
	glRotatef(0, 1.0f, 0.0f, 0.0f);
	BVarray.operator[](1)->DrawSurface();
	glPopMatrix();

	//Front Face
	glPushMatrix();
	glTranslatef(0, 0, size);
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	BVarray.operator[](2)->DrawSurface();
	glPopMatrix();

	//Left Face
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 0.0f, 0.0f, 1.0f);
	BVarray.operator[](4)->DrawSurface();
	glPopMatrix();

	//Right Face
	glPushMatrix();
	glTranslatef(size, 0, 0);
	glRotatef(90, 0.0f, 0.0f, 1.0f);
	BVarray[5]->DrawSurface();
	glPopMatrix();

	glPopMatrix();
}

