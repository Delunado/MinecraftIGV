#include <GL/glut.h>
#include "pch.h"
#include <math.h>
#include <cmath>

#include "igvCamara.h"

// Metodos constructores

igvCamara::igvCamara () {}

igvCamara::~igvCamara () {}

igvCamara::igvCamara(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V) {
	P0 = _P0;
	r = _r;
	V = _V;

	tipo = _tipo;
}


// Metodos publicos 
void igvCamara::set(igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V) {
	P0 = _P0;
	r = _r;
	V = _V;
}
void igvCamara::set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
			                                double _xwmin, double _xwmax, double _ywmin, double _ywmax, double _znear, double _zfar) {
	tipo = _tipo;

	P0 = _P0;
	r = _r;
	V = _V;

	xwmin = _xwmin;
	xwmax = _xwmax;
	ywmin = _ywmin;
	ywmax = _ywmax;
	znear = _znear;
	zfar = _zfar;
}

void igvCamara::set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
			                         double _angulo, double _raspecto, double _znear, double _zfar) {
	tipo = _tipo;

	P0 = _P0;
	r = _r;
	V = _V;

	angulo = _angulo;
	raspecto = _raspecto;
	znear = _znear;
	zfar = _zfar;
}

void igvCamara::MoveForward(double speed)
{
	igvPunto3D forward = r - P0;
	
	//Normalizing
	forward.Normalize();

	//Moving
	P0 += (forward * speed);
	r += (forward * speed);
}

void igvCamara::MoveLateral(double speed)
{
	igvPunto3D forward = r - P0;

	//Normalizing
	forward.Normalize();

	igvPunto3D left = igvPunto3D::CrossProduct(forward, V);

	//Moving
	P0 += (left * speed);
	r += (left * speed);
}

void igvCamara::MoveUp(double speed)
{
	igvPunto3D up = {0,1,0};

	//Moving
	P0 += (up * speed);
	r += (up * speed);
}

void igvCamara::RotateLeft(double speed)
{
	igvPunto3D forward = r - P0;

	//Normalizing
	forward.Normalize();

	igvPunto3D left = igvPunto3D::CrossProduct(V, forward);

	//Moving
	r += (left * speed);
}

void igvCamara::RotateRight(double speed)
{
	igvPunto3D forward = r - P0;

	//Normalizing
	forward.Normalize();

	igvPunto3D right = igvPunto3D::CrossProduct(forward, V);

	//Moving
	r += (right * speed);
}

void igvCamara::RotateUp(double speed)
{
	igvPunto3D forward = r - P0;
	igvPunto3D aux = {0,-1,0};

	//Normalizing
	forward.Normalize();

	igvPunto3D up = igvPunto3D::CrossProduct(aux, forward);

	//Moving
	r += (aux * speed);
}


void igvCamara::RotateDown(double speed)
{
	igvPunto3D forward = r - P0;
	igvPunto3D aux = {0,1,0};

	//Normalizing
	forward.Normalize();

	igvPunto3D Down = igvPunto3D::CrossProduct(forward, aux);

	//Moving
	r += (aux * speed);
}

void igvCamara::aplicar(void) {
	
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();

	if (tipo==IGV_PARALELA) {
		glOrtho(xwmin, xwmax, ywmin, ywmax, znear, zfar);
	}
	if (tipo==IGV_FRUSTUM) {
		glFrustum(xwmin, xwmax, ywmin, ywmax, znear, zfar);
	}
	if (tipo==IGV_PERSPECTIVA) {
		gluPerspective(angulo,raspecto,znear,zfar);
	}
	
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(P0[X],P0[Y],P0[Z], r[X],r[Y],r[Z], V[X],V[Y],V[Z]);
}


void igvCamara::cambiarDistanciaPlano(double factor) {

	set(tipo, P0, r, V, angulo, raspecto, znear += factor, zfar);
}

void igvCamara::zoom(double factor) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (tipo == IGV_PERSPECTIVA) {
		gluPerspective(angulo -= factor, raspecto, znear, zfar);
	}
	else {
		glOrtho(xwmin = xwmin + factor, xwmax = xwmax - factor, ywmin = ywmin + factor, ywmax = ywmax - factor, znear, zfar);
	}

	glMatrixMode(GL_MODELVIEW);
}