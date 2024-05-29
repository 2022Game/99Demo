#pragma once
#include "CCharacter.h"

class CEnemy : public CCharacter
{
public:
	CEnemy(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt);

	void Update();
	bool Collision(CRectangle* rect);
};