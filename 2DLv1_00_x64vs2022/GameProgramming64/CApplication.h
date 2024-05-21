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
public:
	enum class EState
	{
		ESTART,	//ゲーム開始
		EPLAY,	//ゲーム中
		ECLEAR,	//ゲームクリア
		EOVER,	//ゲームオーバー
	};

	//最初に一度だけ実行するプログラム
	void Start();
	//繰り返し実行するプログラム
	void Update();
private:
	EState mState;

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