#include "CRectangle.h"
#include "CApplication.h"


void CApplication::Start()
{
	mPlayer.Set(400.0f, 44.0f, 26.0f, 44.0f);
	mPlayer.Texture(&mTexture, 740, 876, 1236, 1016);
	mTexture.Load("22302021.png");
	mEnemy.Set(26.0f, 574.0f, 44.0f, 26.0f);
	mEnemy.Texture(&mTexture, 1604, 1808, 680, 472);
	mBullet.Set(400.0f, 98.0f, 3.0f, 10.0f);
	mFont.Load("FontWhite.png", 1, 64);
}

void CApplication::Update()
{
	mPlayer.Update();
	mEnemy.Update();
	mBullet.Update();
	mPlayer.Render();
	mEnemy.Render();
	mBullet.Render();

	mEnemy.Collision(&mBullet);
	if (mBullet.Collision(&mEnemy))
	{
		mFont.Draw(370.0f, 300.0f, 15.0f, 30.0f, 'H');
		mFont.Draw(400.0f, 300.0f, 15.0f, 30.0f, 'I');
		mFont.Draw(430.0f, 300.0f, 15.0f, 30.0f, 'T');
		mFont.Draw(370.0f, 240.0f, 15.0f, 30.0f, "PUSH");
		mFont.Draw(370.0f, 180.0f, 15.0f, 30.0f, "ENTER");
	}
}