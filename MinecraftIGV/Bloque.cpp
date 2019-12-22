#include "pch.h"
#include "Bloque.h"
#include <iostream>

Bloque::Bloque(TEXTURES _textureType, int _x, int _y, int _z): textureType(_textureType), x(_x), y(_y), z(_z), side (new Quad())
{
	xMundo = (float)_x * size;
	yMundo = (float)_y * size;
	zMundo = (float)_z * size;
}

Bloque::~Bloque()
{
}

///Deprecated 
void Bloque::SetId(int _id) {
	id = _id;
}

void Bloque::DrawBlock() {
	if (textureType == TEXTURES::NONE)
		return;

	texture->aplicar();

	glPushMatrix();

	glTranslatef(xMundo, yMundo, zMundo);

		//LadoBajo
		glPushMatrix();
			glTranslatef(0, 0, 0);
			glRotatef(0, 1.0f, 0.0f, 0.0f);
			side->pintar_quad(size);
		glPopMatrix();

		//LadoAtras
		glPushMatrix();
			glTranslatef(0, 0, 0);
			glRotatef(-90, 1.0f, 0.0f, 0.0f);
			side->pintar_quad(size);
		glPopMatrix();

		//LadoArriba
		glPushMatrix();
			glTranslatef(0, size, 0);
			glRotatef(0, 1.0f, 0.0f, 0.0f);
			side->pintar_quad(size);
		glPopMatrix();


		//LadoEnfrente
		glPushMatrix();
			glTranslatef(0, 0, size);
			glRotatef(-90, 1.0f, 0.0f, 0.0f);
			side->pintar_quad(size);
		glPopMatrix();

		//LadoAtras
		glPushMatrix();
			glTranslatef(0, 0, 0);
			glRotatef(90, 0.0f, 0.0f, 1.0f);
			side->pintar_quad(size);
		glPopMatrix();

		//LadoEnfrente
		glPushMatrix();
			glTranslatef(size, 0, 0);
			glRotatef(90, 0.0f, 0.0f, 1.0f);
			side->pintar_quad(size);
		glPopMatrix();

	glPopMatrix();
}