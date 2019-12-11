#include "pch.h"
#include "Grid3D.h"
#include <iostream>


Grid3D::Grid3D(int _height, int _width, int _depth): height(_height), width(_width), depth(_depth) 
{
	world = new matrix3D(height, std::vector<std::vector<Bloque*>>(width, std::vector<Bloque*>(depth)));

	for (int x = 0; x < _height; x++) {
		for (int y = 0; y < _width; y++) {
			for (int z = 0; z < _depth; z++) {
				Bloque* auxBlock = new Bloque(-1, x, y, z);
				world[x][y][z].push_back(auxBlock);
				std::cout << "Fallo aqui en grid3D" << std::endl;
			}
		}
	}
}

Grid3D::~Grid3D()
{
}

//IMPLEMENTAR [x + HEIGHT* (y + WIDTH* z)] usando un vector de 1D

Bloque* Grid3D::GetBlock(int x, int y, int z) {
	return world->at(x).at(y).at(z);
}
