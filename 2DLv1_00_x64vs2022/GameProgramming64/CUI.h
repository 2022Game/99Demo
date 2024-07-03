#pragma once
#include "CFont.h"
/*
* CUi
* ユーザーインタフェースクラス
*/
class CUi
{
public:
	//Enemy(敵の数)
	void Enemy(int enemy);

	CUi();
	//Time(時間)
	void Time(int time);
	void Hp(int hp);
	void Render();
private:
	int mEnemy;	//敵の数
	int mHp;
	int mTime;	//経過時間
	CFont mFont;
};
