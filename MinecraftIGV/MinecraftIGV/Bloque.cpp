#include "pch.h"
#include "Bloque.h"


Bloque::Bloque(float _x, float _y, float _z): x(_x), y(_y), z(_z)
{
	for (int i = 0; i < 6; i++)
	{
		sides[i] = new Quad();
	}
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
			sides[0]->pintar_quad(50,50);

		glPopMatrix();

		//LadoAtras
		glPushMatrix();

		glTranslatef(0, 0, 0);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		sides[1]->pintar_quad(50, 50);

		glPopMatrix();

		//LadoArriba
		glPushMatrix();

		glTranslatef(0, 5, 0);
		glRotatef(0, 1.0f, 0.0f, 0.0f);
		sides[1]->pintar_quad(50, 50);

		glPopMatrix();


		//LadoEnfrente
		glPushMatrix();

		glTranslatef(0, 0, 5);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		sides[1]->pintar_quad(50, 50);

		glPopMatrix();

		//LadoAtras
		glPushMatrix();

		glTranslatef(0, 0, 0);
		glRotatef(90, 0.0f, 0.0f, 1.0f);
		sides[1]->pintar_quad(50, 50);

		glPopMatrix();

		//LadoEnfrente
		glPushMatrix();

		glTranslatef(5, 0, 0);
		glRotatef(90, 0.0f, 0.0f, 1.0f);
		sides[1]->pintar_quad(50, 50);

		glPopMatrix();

	glPopMatrix();


}