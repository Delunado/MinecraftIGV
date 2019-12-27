#include "pch.h"
#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"
#include "igvMaterial.h"

// Metodos constructores 
igvEscena3D::igvEscena3D () {
	ejes = true;
	coePhong = 120;
	coeDif = 1.0;
	coeEsp = 1.0;
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

		//LUZ------------------------------------------
		igvColor colorAmb(0.0, 0.0, 0.0, 1.0);
		igvColor colorDif(coeDif, 1.0, 1.0, 1.0);
		igvColor colorEsp(coeEsp, 1.0, 1.0, 1.0);
		const double a0 = 1.0;
		const double a1 = 0.0;
		const double a2 = 0.0;

		igvPunto3D posicion(1.0, 4.0, 1.0);
		igvPunto3D direccion(0.0, -1.0, 0.0);

		igvFuenteLuz fuenteLuzFoco(GL_LIGHT1, posicion, colorAmb, colorDif, colorEsp, a0, a1, a2, direccion, 45, 2);
		fuenteLuzFoco.aplicar();

		//MATERIAL-------------------------------------
		igvColor refAmb(1, 1, 1);
		igvColor refDif(1, 1, 1);
		igvColor refEsp(0.6, 0, 0);
		const double Ns = coePhong;

		igvMaterial material(refAmb, refDif, refEsp, Ns);
		material.aplicar();

		//QUADS----------------------------------------
		worldManager->DrawWorld();

	glPopMatrix(); // restaura la matriz de modelado
}
