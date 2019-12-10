#include "pch.h"
#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"
#include "igvFuenteLuz.h"
#include "igvMaterial.h"
#include "igvTextura.h"
#include "Quad.h"
#include "Bloque.h"

// Metodos constructores 
igvEscena3D::igvEscena3D () {
	ejes = true;
	coePhong = 120;
}

igvEscena3D::~igvEscena3D() {
}


// Metodos publicos 

void pintar_ejes(void) {
  GLfloat rojo[]={1,0,0,1.0};
  GLfloat verde[]={0,1,0,1.0};
  GLfloat azul[]={0,0,1,1.0};

  glMaterialfv(GL_FRONT,GL_EMISSION,rojo);
	glBegin(GL_LINES);
		glVertex3f(1000,0,0);
		glVertex3f(-1000,0,0);
	glEnd();

  glMaterialfv(GL_FRONT,GL_EMISSION,verde);
	glBegin(GL_LINES);
		glVertex3f(0,1000,0);
		glVertex3f(0,-1000,0);
	glEnd();

  glMaterialfv(GL_FRONT,GL_EMISSION,azul);
	glBegin(GL_LINES);
		glVertex3f(0,0,1000);
		glVertex3f(0,0,-1000);
	glEnd();
}


void pintar_quad(float div_x, float div_z) {
	float ini_x = 0.0;
	float ini_z = 0.0;
	float tam_x = 5.0;
	float tam_z = 5.0;

	glNormal3f(0, 1, 0);
	for (int i = 0; i < div_x; i++)
	{
		for (int j = 0; j < div_z; j++)
		{
			glBegin(GL_QUADS);

			glTexCoord2f((ini_x / div_x) / tam_x, 1 - (ini_z / div_z) / tam_z);
			glVertex3f((ini_x / div_x), 0.0, (ini_z / div_z));

			glTexCoord2f((ini_x / div_x) / tam_x, 1 - ((ini_z + tam_z) / div_z) / tam_z);
			glVertex3f((ini_x / div_x), 0.0, (ini_z + tam_z) / div_z);

			glTexCoord2f(((ini_x + tam_x) / div_x) / tam_x, 1 - ((ini_z + tam_z) / div_z) / tam_z);
			glVertex3f((ini_x + tam_x) / div_x, 0.0, (ini_z + tam_z) / div_z);

			glTexCoord2f(((ini_x + tam_x) / div_x) / tam_x, 1 - (ini_z / div_z) / tam_z);
			glVertex3f((ini_x + tam_x) / div_x, 0.0, (ini_z / div_z));

			ini_z += tam_z;
			glEnd();
		}

		ini_x += tam_x;
		ini_z = 0.0;
	}

}


void igvEscena3D::visualizar(void) {
	
	glPushMatrix(); 

		//Ejes-----------------------------------------
		if (ejes) pintar_ejes();

		//Texture--------------------------------------
		igvTextura texture("block.bmp");
		texture.aplicar();

		//QUADS----------------------------------------
		GLfloat white[] = { 1,1,1 };
		glMaterialfv(GL_FRONT, GL_EMISSION, white);
		Bloque bloque;
		bloque.DrawBlock();


	glPopMatrix(); // restaura la matriz de modelado
}
