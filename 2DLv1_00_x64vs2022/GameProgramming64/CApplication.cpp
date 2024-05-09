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
}

void CApplication::Update()
{
	mPlayer.Update();
	mEnemy.Update();
	mBullet.Update();
	mPlayer.Render();
	mEnemy.Render();
	mBullet.Render();
	if (mEnemy.Collision(&mBullet))
	{
		//”š”­‚Ì‰æ‘œ
		mEnemy.Texture(&mTexture, 1946, 2172, 920, 664);
	}
	else
	{
		mEnemy.Texture(&mTexture, 1604, 1808, 680, 472);
	}

}