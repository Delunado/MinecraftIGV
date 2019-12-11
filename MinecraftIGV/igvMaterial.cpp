#include "pch.h"
#include "igvMaterial.h"

// Metodos constructores 

igvMaterial::igvMaterial () {
	
}

igvMaterial::~igvMaterial () {

}

igvMaterial::igvMaterial (const igvMaterial& p) {	//de copia
	Ka = p.Ka;
	Kd = p.Kd;
	Ks = p.Ks;
	Ns = p.Ns;
}

igvMaterial::igvMaterial(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}

// Metodos publicos 

void igvMaterial::aplicar(void) {

	// APARTADO C
	// Aplicar los valores de los atributos del objeto igvMaterial:
	// - coeficiente de reflexión de la luz ambiental
	float refAmbiental[4] = { Ka[R], Ka[G], Ka[B], Ka[A] };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, refAmbiental);
	// - coeficiente de reflexión difuso
	float refDifuso[4] = { Kd[R], Kd[G], Kd[B], Kd[A] };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, refDifuso);
	// - coeficiente de reflesión especular
	float refEspecular[4] = { Ks[R], Ks[G], Ks[B], Ks[A] };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, refEspecular);
	// - exponente de Phong
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, Ns);

	// establecer como color de emisión (0.0, 0.0, 0.0) (el objeto no es una fuente de luz)
	float emision[3] = { 0, 0, 0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emision);


}

void igvMaterial::set(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}



