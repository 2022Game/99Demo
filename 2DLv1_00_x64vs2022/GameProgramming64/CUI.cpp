#include <stdio.h>
#include "CUi.h"

void CUi::Enemy(int enemy)
{
	mEnemy = enemy;
}

CUi::CUi()
	: mTime(0)
	, mHp(0)
{	//フォントファイルのロード
	mFont.Load("FontWhite.png", 1, 64);
}

void CUi::Time(int time)
{
	mTime = time;
}

void CUi::Hp(int hp)
{
	mHp = hp;
}

void CUi::Render()
{
	char str[16];
	sprintf(str, "TIME:%03d", mTime);
	mFont.Draw(620, 580, 10, 20, str);
	sprintf(str, "HP:%d", mHp);
	mFont.Draw(20, 20, 10, 20, str);
	sprintf(str, "ENEMY:%d", mEnemy);
	mFont.Draw(20, 580, 10, 20, str);
}
