#pragma once
#include "stdafx.h"

struct Mesh
{
public:
	Mesh();

	Vertex *vertices;
	int *index;
	int indexSize;

	void initialize();
	void setVerts(Vertex *vert, int indexPool);
	void Draw();


	// draw를 Mesh 구조체 안에서 하기 위해
	bool IsInRange(int x, int y);
	void PutPixel(IntPoint pt);
	
};
