#include "pch.h"
#include "Quad.h"


Quad::Quad()
{
	
}

void Quad::pintar_quad(float div_x, float div_z) {
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



Quad::~Quad()
{
}
