#include "pch.h"
#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"
#include "igvMaterial.h"

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


void igvEscena3D::visualizar(void) {
	
	glPushMatrix(); 

		//Ejes-----------------------------------------
		if (ejes) pintar_ejes();

		//QUADS----------------------------------------
		GLfloat white[] = { 1,1,1 };
		glMaterialfv(GL_FRONT, GL_EMISSION, white);

		igvTextura textura("stone.bmp");
		textura.aplicar();

		glPushMatrix();

			worldManager->DrawWorld();

		glPopMatrix();

	glPopMatrix(); // restaura la matriz de modelado
}
