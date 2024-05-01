#include "CApplication.h"
#include "CRectangle.h"

//�N���X��static�ϐ�
CTexture CApplication::mTexture;
CCharacterManager CApplication::mCharacterManager;

#define SOUND_BGM "res\\mario.wav" //BGM�����t�@�C��
#define SOUND_OVER "res\\mdai.wav" //�Q�[���I�[�o�[�����t�@�C��

CCharacterManager* CApplication::CharacterManager()
{
	return &mCharacterManager;
}

CTexture* CApplication::Texture()
{
	return &mTexture;
}

//�e�N�X�`���t�@�C����
#define TEXTURE2 "22302021.png"
CTexture CApplication::mTexture2;
CTexture* CApplication::Texture2()
{
	return &mTexture2;
}

//�e�N�X�`���t�@�C����
#define TEXTURE3 "117159.png"
CTexture CApplication::mTexture3;
CTexture* CApplication::Texture3()
{
	return &mTexture3;
}

void CApplication::Start()
{
	mTexture3.Load(TEXTURE3);
	mTexture2.Load(TEXTURE2);
	//Sound
	mSoundBgm.Load(SOUND_BGM);
	mSoundOver.Load(SOUND_OVER);

	mFont.Load("FontWhite.png", 1, 64);
	mState = EState::ESTART;
	mpGame = new CGame2();
}

void CApplication::Update()
{
	switch (mState)
	{
	case EState::ESTART:	//��Ԃ��X�^�[�g
		mpGame->Start();	//�X�^�[�g��ʕ\��
		//Enter�L�[�������ꂽ��
		if (mInput.Key(VK_RETURN)
			|| mInput.Key(VK_LBUTTON))
		{	//��Ԃ��v���C���ɂ���
			mState = EState::EPLAY;
			//BGM���s�[�g�Đ�
			mSoundBgm.Repeat();
		}
		break;
	case EState::EPLAY:
		mpGame->Update();
		//�Q�[���I�[�o�[������
		if (mpGame->IsOver())
		{	//��Ԃ��Q�[���I�[�o�[�ɂ���
			mState = EState::EOVER;
			//BGM�X�g�b�v
			mSoundBgm.Stop();
			//�Q�[���I�[�o�[
			mSoundOver.Play();
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
		//�G���^�[�L�[���͎�
		if (mInput.Key(VK_RETURN))
		{	//�Q�[���̃C���X�^���X�폜
			delete mpGame;
			//�Q�[���̃C���X�^���X����
			mpGame = new CGame2();
			//��Ԃ��X�^�[�g�ɂ���
			mState = EState::ESTART;
		}
		break;
	case EState::ECLEAR:
		//�Q�[���N���A����
		mpGame->Clear();
		if (mInput.Key(VK_RETURN))
		{
			delete mpGame;
			mpGame = new CGame2();
			mState = EState::ESTART;
		}
		break;
	}
}
