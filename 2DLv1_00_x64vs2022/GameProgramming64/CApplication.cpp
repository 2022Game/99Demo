#include "CRectangle.h"
#include "CApplication.h"

void CApplication::Start()
{
	mRectangle.Set(400.0f, 42.0f, 26.0f, 44.0f);
	mTexture.Load("22302021.png");
	mEnemy.Set(26.0f, 574.0f, 44.0f, 26.0f);
	mEnemy.Texture(&mTexture, 1604, 1808, 680, 472);
	mRectangle.Texture(&mTexture, 733, 879, 1247, 1006);
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