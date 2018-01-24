#pragma once
#include "LoaderVertexsFromFile.h"
#include <windows.h>   
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <gl\GL.h>
#include <gl\GLU.h>
#include "RESOURCE.H"

class LoadervertexsFromFile
{
public:
	LoadervertexsFromFile( char* _pathForVertices, int _sizeOfVertices, char* _pathForIndicies, int _sizeofIndicies);
	~LoadervertexsFromFile();
	void Draw();
	

private:
	char* pathForVertices;
	int sizeOfVertices;
	char* pathForIndicies;
	int sizeofIndicies;
	std::vector < float > Vertices;
	std::vector < int > Indicies;
	void calcNormal(float v[3][3], float out[3]);
	void ReduceToUnit(float vector[3]);
};
