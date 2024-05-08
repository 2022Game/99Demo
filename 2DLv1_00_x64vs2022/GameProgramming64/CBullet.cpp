#include "CBullet.h"

void CBullet::Update()
{
	float y = Y() + H();
	if (y > 620.f)
	{
		y = 0;
	}
	Y(y);
}

void CBullet::Render()
{
	glColor3f(1.0f, 1.0f, 0.0f);
	CRectangle::Render();
	glColor3f(1.0f, 1.0f, 1.0f);
}
