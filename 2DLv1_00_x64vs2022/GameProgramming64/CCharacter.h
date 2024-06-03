#pragma once
#include "CRectangle.h"
#include "CTexture.h"

class CCharacter : public CRectangle
{
public:
	enum class ETag	//���ʎq
	{
		EZERO,	//�����l
		EBULLET,	//�e
		EENEMY,	//�I
		EPLAYER	//�v���C���[
	};

	//�Փˏ����Q
	virtual void Collision() {};
	//�Փˏ����S
	//Collision(�����̃|�C���^, �Փˑ���̃|�C���^)
	virtual void Collision(CCharacter* m, CCharacter* o) {};

	virtual void Update() = 0;
	void Move();

	enum class EState	//���
	{
		EMOVE,	//�ړ�
		ESTOP	//��~
	};
	CCharacter();
	CTexture* Texture();
	void Texture(CTexture* pTexture,
		int left, int right, int bottom, int top);
	virtual void Render();
	ETag Tag();
protected:
	ETag mTag;	//���ʎq
	EState mState;
private:
	CTexture* mpTexture;
	int mLeft, mRight, mBottom, mTop;
};
