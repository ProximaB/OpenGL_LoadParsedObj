#include <windows.h>   
#include <iostream>
#include <fstream>
#include <gl\GL.h>
#include <gl\GLU.h>
#include "RESOURCE.H"
#include "DemoLoadVertexsFromArray_1.h"


DemoLoadVertexsFromArray_1::DemoLoadVertexsFromArray_1()
{

}

DemoLoadVertexsFromArray_1::~DemoLoadVertexsFromArray_1()
{

}

void DemoLoadVertexsFromArray_1::LoadType1()
{
	GLfloat vertices[8][3] = {
		{ 1, -1, -1 },{ 1, -1, 1 },{ -1, -1, 1 },{ -1, -1, -1 },{ 1, 1, -1 },{ 0.999999, 1, 1.000001 },{ -1, 1, 1 },{ -1, 1, -1 },
	};

	GLint indicies[] = {
		5, 1, 4, 5, 4, 8, 3, 7, 8, 3, 8, 4, 2, 6, 3, 6, 7, 3, 1, 5, 2, 5, 6, 2, 5, 8, 6, 8, 7, 6, 1, 2, 3, 1, 3, 4,
	};

	GLint rozmiar = sizeof(indicies) / sizeof(*indicies);

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < rozmiar; i++) {
		glVertex3fv(vertices[indicies[i] - 1]);
	}
	glEnd();
}

void DemoLoadVertexsFromArray_1::LoadType2()
{
	GLfloat _vertices[] = { 1, -1, -1, 1, -1, 1, -1, -1, 1, -1, -1, -1, 1, 1, -1, 0.999999, 1, 1.000001, -1, 1, 1, -1, 1, -1 };
	//GLfloat test[] = { 100, 101, 111, 200, 201, 222, 300, 301, 302, 400, 401, 402, 500, 501, 600, 601, 602, 700, 701, 702, 800, 801, 802, 900 };

	GLint indicies[] = {
		5, 1, 4, 5, 4, 8, 3, 7, 8, 3, 8, 4, 2, 6, 3, 6, 7, 3, 1, 5, 2, 5, 6, 2, 5, 8, 6, 8, 7, 6, 1, 2, 3, 1, 3, 4,
	};

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36 - 3; i++) {
		glVertex3f(_vertices[(indicies[i] - 1) * 3], _vertices[(indicies[i] - 1) * 3 + 1], _vertices[(indicies[i] - 1) * 3 + 2]);
		//std::cout << "indicies: " << i << "verticies: " << _vertices[(indicies[i] + ((indicies[i] - 1) * 3) - 1)];
	}
	glEnd();

}