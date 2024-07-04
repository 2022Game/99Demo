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
	//��Ԃ��X�^�[�g�ɂ���
	mState = EState::ESTART;
	mpGame = new CGame();
}

void CApplication::Update()
{
	switch (mState)
	{
	case EState::ESTART:	//��Ԃ��X�^�[�g
		mpGame->Start();	//�X�^�[�g��ʕ\��
		//Enter�L�[�������ꂽ��
		if (mInput.Key(VK_RETURN))
		{	//��Ԃ��v���C���ɂ���
			mState = EState::EPLAY;
		}
		break;
	case EState::EPLAY:
		mpGame->Update();
		//�Q�[���I�[�o�[������
		if (mpGame->IsOver())
		{	//��Ԃ��Q�[���I�[�o�[�ɂ���
			mState = EState::EOVER;
		}
		//�Q�[���N���A������
		if (mpGame->IsClear())
		{	//��Ԃ��Q�[���N���A�ɂ���
			mState = EState::ECLEAR;
		}
		break;
	case EState::EOVER:
		//�Q�[���I�[�o�[����
		mpGame->Over();
		break;
	case EState::ECLEAR:
		//�Q�[���N���A����
		mpGame->Clear();
		break;
	}
}