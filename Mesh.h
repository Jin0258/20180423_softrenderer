#pragma once
#include "stdafx.h"

struct Mesh
{
public:
	Mesh() : vertices(NULL), Indices(NULL), ISize(0), VSize(0) { }
	~Mesh();

	Vertex* vertices;
	int* Indices;
	int ISize;
	int VSize;

	void initialize();
	void setVerts(Vertex *vert, size_t indexPool);
	//void setIndices(int* NewIndices, size_t New SIze;
	void Draw();


	// draw를 Mesh 구조체 안에서 하기 위해
	bool IsInRange(int x, int y);
	void PutPixel(IntPoint pt);
	
};
