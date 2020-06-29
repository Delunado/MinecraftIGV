#include "pch.h"
#include <stdio.h>
#include <math.h>

#include "igvPunto3D.h"

// Constructores
igvPunto3D::igvPunto3D() {
	c[X] = c[Y] = c[Z] = 0.0;
}

igvPunto3D::igvPunto3D (const double& x, const double& y, const double& z ) {
	c[X] = x;
	c[Y] = y;
	c[Z] = z;	
}

// Constructor de copia
igvPunto3D::igvPunto3D (const igvPunto3D& p ) {
	c[X] = p.c[X];
	c[Y] = p.c[Y];
	c[Z] = p.c[Z];
}

// Operador de asignación
igvPunto3D& igvPunto3D::operator = (const igvPunto3D& p) {
	c[X] = p.c[X];
	c[Y] = p.c[Y];
	c[Z] = p.c[Z];
	return(*this);
}

int igvPunto3D::operator == (const igvPunto3D& p) {
	return ((fabs(c[X]-p[X])<IGV_EPSILON) && (fabs(c[Y]-p[Y])<IGV_EPSILON) && (fabs(c[Z]-p[Z])<IGV_EPSILON));
}

int igvPunto3D::operator != (const igvPunto3D& p) {
	return ((fabs(c[X]-p[X])>=IGV_EPSILON) || (fabs(c[Y]-p[Y])>=IGV_EPSILON) || (fabs(c[Z]-p[Z])>=IGV_EPSILON));
}

igvPunto3D igvPunto3D::operator-(const igvPunto3D & p)
{
	igvPunto3D auxPoint(c[X] - p.c[X], c[Y] - p.c[Y], c[Z] - p.c[Z]);

	return auxPoint;
}

void igvPunto3D::operator+=(const igvPunto3D & p)
{
	set(c[X] + p.c[X], c[Y] + p.c[Y], c[Z] + p.c[Z]);
}

igvPunto3D igvPunto3D::operator*(const double factor)
{
	igvPunto3D auxPoint(c[X] * factor, c[Y] * factor, c[Z] * factor);
	
	return auxPoint;
}

// Destructor
igvPunto3D::~igvPunto3D() {
}

// Operadores

void igvPunto3D::set( const double& x, const double& y, const double& z) {
	c[X] = x;
	c[Y] = y;
	c[Z] = z;
}

igvPunto3D igvPunto3D::CrossProduct(igvPunto3D & p1, igvPunto3D & p2)
{
	igvPunto3D crossPoint((p1[Y] * p2[Z]) - (p1[Z] * p2[Y]), 
						  (p1[Z] * p2[X]) - (p1[X] * p2[Z]), 
						  (p1[X] * p2[Y]) - (p1[Y] * p2[X]));

	return crossPoint;
}

void igvPunto3D::Normalize()
{
	double absoluteValue = sqrt(pow(c[X], 2) + pow(c[Y], 2) + pow(c[Z], 2));
	set(c[X] / absoluteValue, c[Y] / absoluteValue, c[Z] / absoluteValue);
}

