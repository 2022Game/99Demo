#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CCharacter.h"
#include "CBullet.h"
#include "CEnemy.h"

class CApplication
{
public:
	//�ŏ��Ɉ�x�������s����v���O����
	void Start();
	//�J��Ԃ����s����v���O����
	void Update();
private:
	CBullet mBullet;
//	CRectangle mRectangle;
	CCharacter mRectangle;
	CTexture mTexture;
	CEnemy mEnemy;
};