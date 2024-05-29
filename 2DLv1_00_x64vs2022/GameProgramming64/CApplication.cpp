#include "CRectangle.h"
#include "CApplication.h"


void CApplication::Start()
{
	mpEnemy = new CEnemy(26.0f, 500.0f, 44.0f, 26.0f, 1604, 1808, 680, 472, &mTexture);
	mCharacterManager.Add(mpEnemy);

	mpEnemy = new CEnemy(26.0f, 430.0f, 44.0f, 26.0f, 1604, 1808, 680, 472, &mTexture);
	mCharacterManager.Add(mpEnemy);

	mpPlayer = new CPlayer();
	mpBullet = new CBullet(400.0f, -98.0f, 3.0f, 20.0f, 1396, 1420, 750, 592, &mTexture);
	mpEnemy = new CEnemy(26.0f, 574.0f, 44.0f, 26.0f, 1604, 1808, 680, 472, &mTexture);
	mpMiss = new CMiss();

	mpPlayer->Set(400.0f, 44.0f, 26.0f, 44.0f);
	mpPlayer->Texture(&mTexture, 740, 876, 1236, 1016);
	mTexture.Load("22302021.png");

	mpBullet->Set(400.0f, 98.0f, 3.0f, 10.0f);
	mFont.Load("FontWhite.png", 1, 64);
	mpBullet->Set(400.0f, -98.0f, 3.0f, 10.0f);
	mpMiss->Set(400.0f, 630.0f, 400.0f, 10.0f);
	mState = EState::EPLAY;
	mCharacterManager.Add(mpPlayer);
	mCharacterManager.Add(mpEnemy);
	mCharacterManager.Add(mpBullet);
	mCharacterManager.Add(mpMiss);
}

void CApplication::Update()
{
	switch (mState)
	{
	case EState::EPLAY:

		if (mInput.Key(VK_SPACE))
		{
			mCharacterManager.Add(
				new CBullet(mpPlayer->X(), mpPlayer->Y() + mpPlayer->H() + 10.0f
					, 3.0f, 10.0f, 1396, 1420, 750, 592, &mTexture));

		}

		mCharacterManager.Update();
		mCharacterManager.Render();

		//mpEnemy->Collision(mpBullet);
		//if (mpBullet->Collision(mpEnemy))
		//{
		//	mFont.Draw(370.0f, 300.0f, 15.0f, 30.0f, 'H');
		//	mFont.Draw(400.0f, 300.0f, 15.0f, 30.0f, 'I');
		//	mFont.Draw(430.0f, 300.0f, 15.0f, 30.0f, 'T');
		//	mFont.Draw(370.0f, 240.0f, 15.0f, 30.0f, "PUSH");
		//	mFont.Draw(370.0f, 180.0f, 15.0f, 30.0f, "ENTER");
		//	mState = EState::ECLEAR;
		//}
		//if (mpBullet->Collision(mpMiss))
		//{
		//	mFont.Draw(370.0f, 300.0f, 15.0f, 30.0f, "MISS");
		//	mState = EState::EOVER;
		//}
		break;
	case EState::EOVER:
		mCharacterManager.Render();

		mFont.Draw(370.0f, 300.0f, 15.0f, 30.0f, "MISS");
		mFont.Draw(370.0f, 240.0f, 15.0f, 30.0f, "PUSH");
		mFont.Draw(370.0f, 180.0f, 15.0f, 30.0f, "ENTER");
		if (mInput.Key(VK_RETURN))
		{
			mState = EState::ESTART;
		}
		break;
	case EState::ECLEAR:
		mCharacterManager.Render();

		mFont.Draw(370.0f, 300.0f, 15.0f, 30.0f, "HIT");
		mFont.Draw(370.0f, 240.0f, 15.0f, 30.0f, "PUSH");
		mFont.Draw(370.0f, 180.0f, 15.0f, 30.0f, "ENTER");
		if (mInput.Key(VK_RETURN))
		{
			mState = EState::ESTART;
		}
		break;
	default:
		mpPlayer->Set(400.0f, 44.0f, 26.0f, 44.0f);
		mpPlayer->Texture(&mTexture, 740, 876, 1236,
			1016);
		mpEnemy->Set(26.0f, 574.0f, 44.0f, 26.0f);
		mpEnemy->Texture(&mTexture, 1604, 1808, 680,
			472);
		mpEnemy->Move();
		mpBullet->Set(400.0f, -98.0f, 3.0f, 10.0f);
		mState = EState::EPLAY;
		break;
	}
}