#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CCharacter.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CPlayer.h"
#include "CFont.h"
#include "CMiss.h"

class CApplication
{
public:
	//最初に一度だけ実行するプログラム
	void Start();
	//繰り返し実行するプログラム
	void Update();
private:
	CMiss mMiss;
	CInput mInput;
	CFont mFont;
	CPlayer mPlayer;
	CBullet mBullet;
//	CRectangle mRectangle;
	CCharacter mRectangle;
	CTexture mTexture;
	CEnemy mEnemy;
};