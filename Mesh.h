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


	// draw�� Mesh ����ü �ȿ��� �ϱ� ����
	bool IsInRange(int x, int y);
	void PutPixel(IntPoint pt);
	
};
