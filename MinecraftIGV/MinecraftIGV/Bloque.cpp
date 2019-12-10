#include "pch.h"
#include "Bloque.h"
#include <iostream>

Bloque::Bloque(float _x, float _y, float _z): side (new Quad())
{
	x = _x * size;
	y = _y * size;
	z = _z * size;
}

Bloque::~Bloque()
{
}


void Bloque::DrawBlock() {

	glPushMatrix();

	glTranslatef(x, y, z);

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