#pragma once
#include "CFont.h"
/*
* CUi
* ���[�U�[�C���^�t�F�[�X�N���X
*/
class CUi
{
public:
	CUi();
	//Time(����)
	void Time(int time);
	void Hp(int hp);
	void Render();
private:
	int mHp;
	int mTime;	//�o�ߎ���
	CFont mFont;
};
