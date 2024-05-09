#pragma once
#include "CCharacter.h"

class CBullet : public CCharacter
{
public:
	bool Collision(CRectangle* rect);
	void Update();
	void Render();
};
