#include "CRectangle.h"
#include "CApplication.h"


void CApplication::Start()
{
	mRectangle.Set(400.0f, 50.0f, 26.0f, 44.0f);
	mTexture.Load("22302021.png");
	mEnemy.Set(26.0f, 574.0f, 44.0f, 26.0f);
	mEnemy.Texture(&mTexture, 1604, 1808, 680, 472);
	mRectangle.Texture(&mTexture, 720, 895, 1230, 1008);
	mBullet.Set(400.0f, 98.0f, 3.0f, 10.0f);
}

void CApplication::Update()
{
	mEnemy.Update();
	mBullet.Update();
	mRectangle.Render();
	mEnemy.Render();
	mBullet.Render();
}