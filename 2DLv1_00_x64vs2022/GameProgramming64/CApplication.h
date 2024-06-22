#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CCharacter.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CPlayer.h"
#include "CFont.h"
#include "CMiss.h"
#include "CCharacterManager.h"
#include "CGame.h"

class CApplication
{
public:
	static CTexture* Texture();
	static CCharacterManager* CharacterManager();
	static CCharacterManager mCharacterManager;
	enum class EState
	{
		ESTART,	//�Q�[���J�n
		EPLAY,	//�Q�[����
		ECLEAR,	//�Q�[���N���A
		EOVER,	//�Q�[���I�[�o�[
	};

	//�ŏ��Ɉ�x�������s����v���O����
	void Start();
	//�J��Ԃ����s����v���O����
	void Update();
private:
	CGame* mpGame;
	EState mState;

	CMiss* mpMiss;
	CInput mInput;
	CFont mFont;
	CPlayer* mpPlayer;
	CBullet* mpBullet;
//	CRectangle mRectangle;
	//CCharacter mRectangle;
	static CTexture mTexture;
	CEnemy* mpEnemy;
};