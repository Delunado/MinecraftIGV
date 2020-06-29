#include "pch.h"
#include "SelectionController.h"


SelectionController::SelectionController(): idTotalVolumes(0), BVMap()
{
}


SelectionController::~SelectionController()
{
}

/** 
Esta funcion guarda los Bounding Volume de un Bloque en el mapa de BoundingVolume, y les asigna
un color único a cada Bounding Volume.
*/
void SelectionController::AddBoundingVolumes(Block* block)
{
	//std::cout << block->x << ", " << block->y << ", " << block->z << std::endl;
	std::vector<BoundingVolumeQuad*> auxVectorVB = block->GetBVArray();

	for (int i = 0; i < 6; i++)
	{
		BoundingVolumeQuad* BVaux = auxVectorVB[i];
		IDtoColor(idTotalVolumes, BVaux->GetColor());
		std::pair<int, BoundingVolumeQuad*> pairIDBV(idTotalVolumes++, BVaux);
		BVMap.insert(pairIDBV);
	}
}

Block * SelectionController::GetBlock(GLfloat color[3])
{
	int ID = ColortoID(color);

	if (BVMap.count(ID)) {
		return BVMap.operator[](ID)->GetBlock();
	}

}

POSITION SelectionController::GetPosition(GLfloat color[3])
{
	int ID = ColortoID(color);

	if (BVMap.count(ID))
		return BVMap.operator[](ID)->GetPosition();
}



