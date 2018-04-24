
#include "stdafx.h"
#include "SoftRenderer.h"
#include "GDIHelper.h"
#include "Mesh.h"
#include "Triangle.h"

Mesh::~Mesh()
{
	if (NULL != vertices)
	{
		delete[] vertices;
		vertices = NULL;
	}

	if (NULL != Indices)
	{
		delete[] Indices;
		Indices = NULL;
	}
}

void Mesh::initialize()
{
	vertices = NULL;
	Indices = NULL;
	ISize = 0;
}

void Mesh::setVerts(Vertex *vert, size_t indexPool)
{
	
	initialize();// 초기화

	vertices = vert;
	ISize = indexPool;
	Indices = new int[ISize];

	for (int i = 0; i < ISize; i++)
	{
		Indices[i] = i;
	}
}

void Mesh::Draw()
{
	for (int i = 0; i < ISize; i += 3)// 3번마다 반복
	{
		Vertex vert[3];
		
		vert[0] = vertices[Indices[i]];
		vert[1] = vertices[Indices[i + 1]];
		vert[2] = vertices[Indices[i + 2]];

		Triangle primitive(vert[0], vert[1], vert[2]);

		//프리미티브 하나 그림
		for (int y = primitive.Min.Y; y <= primitive.Max.Y; y++)
		{
			for (int x = primitive.Min.X; x <= primitive.Max.X; x++)
			{
				Vector3 target((float)x + 0.5f, (float)y + 0.5f, 0.0f);
				float outS, outT;
				primitive.CalcBaryCentricCoord(target, &outS, &outT);

				if (g_Texture->IsLoaded())
				{
					g_CurrentColor = g_Texture->GetTexturePixel(outS, outT, primitive);
				}
				else
				{
					g_CurrentColor = primitive.GetPixelColor(target, outS, outT);
				}

				PutPixel(IntPoint(x, y));
				
			}
		}

	}
}

bool Mesh::IsInRange(int x, int y)
{
	return (abs(x) < (g_nClientWidth / 2)) && (abs(y) < (g_nClientHeight / 2));
}

void Mesh::PutPixel(IntPoint pt)
{
	if (!IsInRange(pt.X, pt.Y)) return;

	ULONG* dest = (ULONG*)g_pBits;

	int halfWidth = RoundToInt(g_nClientWidth * 0.5f);
	int halfHeight = RoundToInt(g_nClientHeight * 0.5f);

	DWORD offset = (halfHeight * g_nClientWidth - g_nClientWidth * pt.Y) + (halfWidth + pt.X);
	*(dest + offset) = g_CurrentColor;
}
