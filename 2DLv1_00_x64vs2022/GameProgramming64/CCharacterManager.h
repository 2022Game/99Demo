#pragma once
#include "CCharacter.h"
#include <vector>
/*
  CCharacter�N���X�̃C���X�^���X���Ǘ�����
*/
class CCharacterManager
{
public:
	//�S�C���X�^���X�폜
	void AllDelete();

	//�����ȃ|�C���^���폜����
	void Delete();

	//�Փˏ����P
	void Collision();
	//�Փˏ����R
	//Collision(�Փˌ��̃|�C���^)
	void Collision(CCharacter* character);

	//Add(CChracter�̃|�C���^)
	//�ϒ��z��̌��ɒǉ�����
	void Add(CCharacter* c);
	//�ϒ��z��ɂ���|�C���^��Update()�����s���Ă���
	void Update();
	//�ϒ��z��ɂ���|�C���^��Render()�����s���Ă���
	void Render();
private:
	//CCharacter�̃|�C���^�̉ϒ��z��
	std::vector<CCharacter*> mpCharacters;
};
