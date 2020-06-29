#pragma once

#include "BoundingVolumeQuad.h"
#include "Bloque.h"
#include <stack>
#include <map>
#include <array>

class SelectionController
{
private:
	int idTotalVolumes; //ID of BoundingVolumeQuads
	std::map<int, BoundingVolumeQuad*> BVMap;

	void IDtoColor(int id, GLint* color) {
		int r = (id & 0x000000FF) >> 0;
		int g = (id & 0x0000FF00) >> 8;
		int b = (id & 0x00FF0000) >> 16;

		color[0] = r;
		color[1] = g;
		color[2] = b;
	}

	int ColortoID(GLfloat color[3]) {
		int id =
			(int)(color[0] * 255.0f) +
			(int)(color[1] * 255.0f * 256) +
			(int)(color[2] * 255.0f * 256 * 256);

		return id;
	}

public:
	SelectionController();
	~SelectionController();

	void AddBoundingVolumes(Block* block);
	Block* GetBlock(GLfloat color[3]);
	POSITION GetPosition(GLfloat color[3]);

};

