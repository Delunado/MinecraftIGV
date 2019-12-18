#include "pch.h"
#include "Grid3D.h"
#include <iostream>


Grid3D::Grid3D(int _width, int _height, int _depth): height(_height), width(_width), depth(_depth) 
{
	long totalSize = height * width * depth;
	std::cout << "Creado Grid de tam: " << totalSize << std::endl;

	world = new std::vector<Bloque*>;

	for (int x = 0; x < _width; x++) {
		for (int y = 0; y < _height; y++) {
			for (int z = 0; z < _depth; z++) {
				world->push_back(new Bloque(-1, x, y, z));
				//std::cout << "Pos en matriz: " << x << ", " << y << ", " << z << " - Pos en vector: " << x * height * depth + y * depth + z << std::endl;
			}
		}
	}
}

Grid3D::~Grid3D()
{
}

Bloque* Grid3D::GetBlock(int x, int y, int z) {
	return world->at(x * height * depth + y * depth + z);
}
