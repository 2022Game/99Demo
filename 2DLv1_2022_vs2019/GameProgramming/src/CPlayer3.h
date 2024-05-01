#pragma once
#include "CCharacter.h"
#include "CInput.h"
#include "CSound.h"

class CPlayer3 : public CCharacter
{
public:
	static CPlayer3* Instance();
	//HPを取得
	static int Hp();
	//衝突処理2
	void Collision();
	//衝突処理4
	void Collision(CCharacter* m, CCharacter* o);
	//CPlayer2(X座標,Y座標,幅,高さ,テクスチャのポインタ)
	CPlayer3(float x, float y, float w, float h, CTexture* pt);
	//更新処理
	void Update();
private:
	static CPlayer3* spInstance;
	CSound mSoundJump;	//ジャンプSE
	static int sHp;	//HP
	int mInvincible; //無敵カウンタ
	CInput mInput;
};