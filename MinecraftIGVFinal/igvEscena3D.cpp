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

void pintar_ejes(int xSize, int ySize, int zSize) {
  GLfloat rojo[]={1,0,0,1.0};
  GLfloat verde[]={0,1,0,1.0};
  GLfloat azul[]={0,0,1,1.0};

  glMaterialfv(GL_FRONT,GL_EMISSION,rojo);
	glBegin(GL_LINES);
		glVertex3f(0,0,0);
		glVertex3f(xSize,0,0);
	glEnd();

  glMaterialfv(GL_FRONT,GL_EMISSION,verde);
	glBegin(GL_LINES);
		glVertex3f(0,0,0);
		glVertex3f(0,ySize,0);
	glEnd();

  glMaterialfv(GL_FRONT,GL_EMISSION,azul);
	glBegin(GL_LINES);
		glVertex3f(0,0,0);
		glVertex3f(0,0,zSize);
	glEnd();
}


void igvEscena3D::visualizar(void) {
	
	glPushMatrix(); 

		//Ejes-----------------------------------------
		if (ejes) pintar_ejes(worldManager->GetWorldWidth(), worldManager->GetWorldHeight(), worldManager->GetWorldDepth());

		//LUZ------------------------------------------
		igvPunto3D posicion((1.0 * worldManager->GetWorldWidth() / 2), (1.0 * worldManager->GetWorldHeight()*2), (1.0 * worldManager->GetWorldDepth() / 2));
		igvPunto3D direccion(0.0f, -1.0, 0.0f);

		igvFuenteLuz fuenteLuzFoco(GL_LIGHT1, posicion, igvColor(0.0, 0.0, 0.0, 1.0), igvColor(coeDif, 1.0, 1.0, 1.0), igvColor(coeEsp, 1.0, 1.0, 1.0), 1.0, 0.0, 0.0, direccion, 45, 2);
		fuenteLuzFoco.aplicar();

		//MATERIAL-------------------------------------
		igvMaterial material(igvColor(1, 1, 1), igvColor(1, 1, 1), igvColor(0.6, 0, 0), coePhong);
		material.aplicar();

		//DIBUJADO DEL MUNDO----------------------------------------
		worldManager->DrawWorld();

	glPopMatrix();
}
