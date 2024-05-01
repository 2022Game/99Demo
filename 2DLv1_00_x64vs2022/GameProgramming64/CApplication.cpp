#include "CRectangle.h"
#include "CApplication.h"

void CApplication::Start()
{
	mRectangle.Set(400.0f, 50.0f, 40.0f, 46.0f);
	mRectangle.Texture(&mTexture, 710, 880, 1200, 1010);
	mTexture.Load("22302021.png");
	mCharacter.Set(26.0f, 574.0f, 44.0f, 26.0f);
	mCharacter.Texture(&mTexture, 1604, 1808, 680, 472);
}

void CApplication::Update()
{
	mRectangle.Render();
	mCharacter.Render();

}

