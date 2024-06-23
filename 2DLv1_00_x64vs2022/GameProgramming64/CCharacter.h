#pragma once
#include "CRectangle.h"
#include "CTexture.h"

class CCharacter : public CRectangle
{
public:
	bool Enabled();
	enum class ETag	//識別子
	{
		EZERO,	//初期値
		EBULLET,	//弾
		EENEMY,	//的
		EPLAYER	//プレイヤー
	};

	//衝突処理２
	virtual void Collision() {};
	//衝突処理４
	//Collision(自分のポインタ, 衝突相手のポインタ)
	virtual void Collision(CCharacter* m, CCharacter* o) {};

	virtual void Update() = 0;
	void Move();

	enum class EState	//状態
	{
		EMOVE,	//移動
		ESTOP,	//停止
		EJUMP,	//ジャンプ
	};
	CCharacter();
	CTexture* Texture();
	void Texture(CTexture* pTexture,
		int left, int right, int bottom, int top);
	virtual void Render();
	ETag Tag();
protected:
	float mVy;	//Y軸速度
	bool mEnabled; //有効フラグ
	ETag mTag;	//識別子
	EState mState;
private:
	CTexture* mpTexture;
	int mLeft, mRight, mBottom, mTop;
};
