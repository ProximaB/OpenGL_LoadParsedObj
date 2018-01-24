#pragma once
#include "LoaderVertexsFromFile.h"
#include <windows.h>   
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <gl\GL.h>
#include <gl\GLU.h>


LoadervertexsFromFile::LoadervertexsFromFile(char* _pathForVertices, int _sizeOfVertices, char* _pathForIndicies, int _sizeofIndicies)
{
	LoadervertexsFromFile::pathForVertices = _pathForVertices;
	LoadervertexsFromFile::sizeOfVertices = _sizeOfVertices;
	LoadervertexsFromFile::pathForIndicies = _pathForIndicies;
	LoadervertexsFromFile::sizeofIndicies = _sizeofIndicies;


	int count = 0;
	std::ifstream inputFile;

	inputFile.open(pathForIndicies);

	if (inputFile.is_open()) {
		std::cout << "Otworzono plik Faces.txt";
	}
	int temp = int();
	while (count < sizeofIndicies && inputFile >> temp) { //push_back
		LoadervertexsFromFile::Indicies.push_back(temp);
		count++;
	}

	inputFile.close();

	int _count = 0;

	std::ifstream _inputFile;

	_inputFile.open(pathForVertices);

	if (inputFile.is_open()) {
		std::cout << "Otworzono plik Vertex.txt";
	}
	
	float temp2 = float();
	while (_count < sizeOfVertices && _inputFile >> temp2) {
		LoadervertexsFromFile::Vertices.push_back(temp2);
		_count++;
	}

	_inputFile.close();


}

LoadervertexsFromFile::~LoadervertexsFromFile()
{
}


void LoadervertexsFromFile::Draw() {

	//GLint rozmiar = sizeof(Indicies) / sizeof(*Indicies);

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < Indicies.size() - 3; i++) {
		glVertex3f(Vertices[(Indicies[i] - 1) * 3], Vertices[(Indicies[i] - 1) * 3 + 1], Vertices[(Indicies[i] - 1) * 3 + 2]);
		//std::cout << "indicies: " << i << "verticies: " << Vertices[(Indicies[i] + ((Indicies[i] - 1) * 3) - 1)];
	}
	glEnd();

}