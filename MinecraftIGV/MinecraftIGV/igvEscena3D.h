#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include "igvFuenteLuz.h"
#include "igvMallaTriangulos.h"
#include "WorldManager.h"


class igvEscena3D {
	protected:
		// Atributos

		bool ejes;
		double coeDif;
		double coeEsp;
		double coePhong;

		double posXFoco, posYFoco;

		WorldManager* worldManager;

	public:
		// atributos públicos

		// Constructores por defecto y destructor
		igvEscena3D();
		~igvEscena3D();

		// Metodos estáticos

		// Métodos
		// método con las llamadas OpenGL para visualizar la escena
    void visualizar();

		bool get_ejes() {return ejes;};
		void set_ejes(bool _ejes){ejes = _ejes;};

};

#endif
