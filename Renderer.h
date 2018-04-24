#pragma once
#include "Mesh.h"

void InitFrame(void);
void UpdateFrame(void);
bool IsInRange(int x, int y);
void PutPixel(IntPoint pt);
void DrawCall(Mesh *mesh);

VertexToFragment VertexShader(VertexDATA in);
ULONG FragmentShader(VertexToFragment in);
