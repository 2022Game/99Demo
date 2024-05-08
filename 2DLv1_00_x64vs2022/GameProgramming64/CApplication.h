#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CCharacter.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CPlayer.h"

class CApplication
{
public:
	//最初に一度だけ実行するプログラム
	void Start();
	//繰り返し実行するプログラム
	void Update();
private:
	CPlayer mPlayer;
	CBullet mBullet;
//	CRectangle mRectangle;
	CCharacter mRectangle;
	CTexture mTexture;
	CEnemy mEnemy;
};