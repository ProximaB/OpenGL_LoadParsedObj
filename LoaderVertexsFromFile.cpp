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
	float norm[3];
	
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < Indicies.size() - 3; i++) {
		glVertex3f(Vertices[(Indicies[i] - 1) * 3], Vertices[(Indicies[i] - 1) * 3 + 1], Vertices[(Indicies[i] - 1) * 3 + 2]);

		float v [3][3] = { Vertices[(Indicies[i] - 1) * 3], Vertices[(Indicies[i] - 1) * 3 + 1], Vertices[(Indicies[i] - 1) * 3 + 2]};
		calcNormal(v, norm);
		glNormal3d(norm[0], norm[1], norm[2]);
	}
	glEnd();
}

void LoadervertexsFromFile::calcNormal(float v[3][3], float out[3])
{
	float v1[3], v2[3];
	static const int x = 0;
	static const int y = 1;
	static const int z = 2;

	// Calculate two vectors from the three points
	v1[x] = v[0][x] - v[1][x];
	v1[y] = v[0][y] - v[1][y];
	v1[z] = v[0][z] - v[1][z];

	v2[x] = v[1][x] - v[2][x];
	v2[y] = v[1][y] - v[2][y];
	v2[z] = v[1][z] - v[2][z];

	// Take the cross product of the two vectors to get
	// the normal vector which will be stored in out
	out[x] = v1[y] * v2[z] - v1[z] * v2[y];
	out[y] = v1[z] * v2[x] - v1[x] * v2[z];
	out[z] = v1[x] * v2[y] - v1[y] * v2[x];

	// Normalize the vector (shorten length to one)
	ReduceToUnit(out);
}

void LoadervertexsFromFile:: ReduceToUnit(float vector[3])
{
	float length;

	// Calculate the length of the vector      
	length = (float)sqrt((vector[0] * vector[0]) +
		(vector[1] * vector[1]) +
		(vector[2] * vector[2]));

	// Keep the program from blowing up by providing an exceptable
	// value for vectors that may calculated too close to zero.
	if (length == 0.0f)
		length = 1.0f;

	// Dividing each element by the length will result in a
	// unit normal vector.
	vector[0] /= length;
	vector[1] /= length;
	vector[2] /= length;
}