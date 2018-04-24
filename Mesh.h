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


	// draw�� Mesh ����ü �ȿ��� �ϱ� ����
	bool IsInRange(int x, int y);
	void PutPixel(IntPoint pt);
	
};
