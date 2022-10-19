#pragma once
#include "CCharacter.h"
#include "CInput.h"
#include "CSound.h"

class CPlayer3 : public CCharacter
{
public:
	static CPlayer3* Instance();
	//HP���擾
	static int Hp();
	//�Փˏ���2
	void Collision();
	//�Փˏ���4
	void Collision(CCharacter* m, CCharacter* o);
	//CPlayer2(X���W,Y���W,��,����,�e�N�X�`���̃|�C���^)
	CPlayer3(float x, float y, float w, float h, CTexture* pt);
	//�X�V����
	void Update();
private:
	static CPlayer3* spInstance;
	CSound mSoundJump;	//�W�����vSE
	static int sHp;	//HP
	int mInvincible; //���G�J�E���^
	CInput mInput;
};