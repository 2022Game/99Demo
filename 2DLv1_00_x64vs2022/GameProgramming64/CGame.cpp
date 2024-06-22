#include "CGame.h"
#include "CApplication.h"
#include "CBlock.h"

CGame::CGame()
{
	//�e�N�X�`���̓���
	CApplication::Texture()->Load(TEXTURE);
	//�u���b�N�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
	CApplication::CharacterManager()->Add(
		new CBlock(400.0f, 300.0f, TIPSIZE, TIPSIZE,
			CApplication::Texture()));
}

void CGame::Update()
{
	//�X�V�A�ՓˁA�폜�A�`��
	CApplication::CharacterManager()->Update();
	CApplication::CharacterManager()->Collision();
	CApplication::CharacterManager()->Delete();
	CApplication::CharacterManager()->Render();
}
