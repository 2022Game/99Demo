#pragma once
#include "CRectangle.h"
#include "CTexture.h"

class CCharacter : public CRectangle
{
public:
	bool Enabled();
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
		ESTOP,	//��~
		EJUMP,	//�W�����v
	};
	CCharacter();
	CTexture* Texture();
	void Texture(CTexture* pTexture,
		int left, int right, int bottom, int top);
	virtual void Render();
	ETag Tag();
protected:
	float mVy;	//Y�����x
	bool mEnabled; //�L���t���O
	ETag mTag;	//���ʎq
	EState mState;
private:
	CTexture* mpTexture;
	int mLeft, mRight, mBottom, mTop;
};
