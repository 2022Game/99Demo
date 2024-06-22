#include "CRectangle.h"
#include "CApplication.h"

CCharacterManager CApplication::mCharacterManager;
CTexture CApplication::mTexture;

CTexture* CApplication::Texture()
{
	return &mTexture;
}

CCharacterManager* CApplication::CharacterManager()
{
	return &mCharacterManager;
}

void CApplication::Start()
{
	mFont.Load("FontWhite.png", 1, 64);
	mState = EState::EPLAY;
	mpGame = new CGame();
}

void CApplication::Update()
{
	switch (mState)
	{
	case EState::EPLAY:
		mpGame->Update();
		break;
	}
}