#include "pch.h"
#include "igvTextura.h"
#include <iostream>

// Metodos constructores y destructor

igvTextura::igvTextura(const char *fichero) {
	GLubyte *imagen;

	imagen = loadBMPRaw(fichero, alto, ancho);

	/* Apartado G: Añadir aquí el código para cargar como textura OpenGL el BMP imagen */
	glEnable(GL_TEXTURE_2D);
	//- Generar el identificador de textura y asignarlo al atributo idTextura
	glGenTextures(1, &idTextura);
	//- Enlazar el identificador creado a GL_TEXTURE_2D
	glBindTexture(GL_TEXTURE_2D, idTextura);
	//- Especificar la textura, asignádole como textura el array imagen
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ancho, alto, 0, GL_RGB, GL_UNSIGNED_BYTE, imagen);

	//- Modo de aplicación de la 
	glTexEnvf(GL_TEXTURE_ENV, GL_REPLACE, 1);
	glTexEnvf(GL_TEXTURE_ENV, GL_BLEND, 1);

	//- Parámetros de la textura: repetición y filtros
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	delete imagen;

	std::cout << "Creado con ID: " << idTextura << std::endl;
}

void igvTextura::aplicar(void) {
  glBindTexture(GL_TEXTURE_2D, idTextura);
}

igvTextura::~igvTextura() {
  glDeleteTextures(1, &idTextura); 
}
