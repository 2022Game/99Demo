#pragma once
#include "CFont.h"
/*
* CUi
* ユーザーインタフェースクラス
*/
class CUi
{
public:
	CUi();
	//Time(時間)
	void Time(int time);
	void Hp(int hp);
	void Render();
private:
	int mHp;
	int mTime;	//経過時間
	CFont mFont;
};
