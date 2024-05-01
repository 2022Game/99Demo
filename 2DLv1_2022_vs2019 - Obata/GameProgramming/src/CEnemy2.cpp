#include "CEnemy2.h"
#include "CApplication.h"

#define TEXCOORD 168, 188, 190, 160	//テクスチャマッピング
#define TEXCRY 196, 216, 190, 160	//テクスチャマッピング
#define GRAVITY (TIPSIZE / 20.0f)	//重力加速度


#define TEXCOORD2 136,156,190,160	//右向き2
#define TEXLEFT1 188,168,190,160	//左向き1
#define TEXLEFT2 156,136,190,160	//左向き2

int CEnemy2::sNum = 0;

void CEnemy2::Num(int num)
{
	sNum = num;
}

int CEnemy2::Num()
{
	return sNum;
}

void CEnemy2::Collision()
{
	CApplication::CharacterManager()->Collision(this);
}

void CEnemy2::Collision(CCharacter* m, CCharacter* o)
{
	//めり込み調整変数を宣言する
	float x, y;
	switch (o->Tag())
	{
	case ETag::ETURN:
		//折り返しに当たった時
		if (CRectangle::Collision(o, &x, &y))
		{
			//めり込まない位置まで戻す
			X(X() + x);
			Y(Y() + y);
			//X軸速度を反転させる
			mVx = -mVx;
		}
		break;
	case ETag::EENEMY:
		break;
	case ETag::EPLAYER:
		if (CRectangle::Collision(o))
		{
			if (o->State() == EState::EJUMP)
			{
				//敵数1減算
				if (mState != EState::ECRY)
				{
					sNum--;
				}
				mState = EState::ECRY;
			}
		}
	case ETag::EBLOCK:
		if (CRectangle::Collision(o, &x, &y))
		{
			X(X() + x);
			Y(Y() + y);
			//着地した時
			if (y != 0.0f)
			{
				//Y軸速度を0にする
				mVy = 0.0f;
				if (y > 0.0f)
				{
					mState = EState::EMOVE;
				}
			}
		}
		break;
	}
}

CEnemy2::CEnemy2(float x, float y, float w, float h, CTexture* pt)
{
	Set(x, y, w, h);
	Texture(pt, TEXLEFT1);
	mTag = ETag::EENEMY;
	//X軸速度の初期値を移動速度にする
	mVx = VELOCITY;
	//敵数に1加算する
	sNum++;
}

void CEnemy2::Update()
{
	switch (mState)
	{
	case EState::ECRY:
		//泣く画像を設定
		Texture(Texture(), TEXCRY);
		break;
	case EState::EMOVE:
		//X軸速度分、X座標を更新する
		X(X() - mVx);
		const int PITCH = 32;//画像を切り替える間隔
		if ((int)X() % PITCH < PITCH / 2)
		{
			if (mVx < 0.0f) //左へ移動
			{
				//左向き１を設定
				Texture(Texture(), TEXCOORD);
			}
			else
			{
				//通常の画像を設定
				Texture(Texture(), TEXLEFT1);
			}
		}
		else
		{
			if (mVx < 0.0f) //左へ移動
			{
				//左向き2を設定
				Texture(Texture(), TEXCOORD2);
			}
			else
			{
				//2番目の画像を設定
				Texture(Texture(), TEXLEFT2);
			}
		}
		break;
	}
	//Y座標にY軸速度を加える
	Y(Y() + mVy);
	//Y軸速度に重力を減算する
	mVy -= GRAVITY;
}
