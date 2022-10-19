#include "CGame2.h"
#include "CApplication.h"
#include "CBlock.h"
#include "CPlayer3.h"
#include "CEnemy3.h"
#include "CPoint.h"
#include "CCamera.h"
#include "main.h"

void CGame2::Start()
{
	//	CameraSet();
		//�Q�[���̕`��
	CApplication::CharacterManager()->Render();
	//	CCamera::End();
		//UI����
	mpUi->Hp(CPlayer3::Hp());
	mpUi->Enemy(CEnemy3::Num());
	mpUi->Render();
	mpUi->Start();
}

bool CGame2::IsOver()
{	//HP��0�ȉ������茋�ʂ�߂�
	return CPlayer3::Hp() <= 0;
}

void CGame2::Over()
{
	CameraSet();
	//�Q�[���̕`��
	CApplication::CharacterManager()->Render();
	CCamera::End();
	//UI����
	mpUi->Hp(CPlayer3::Hp());
	mpUi->Enemy(CEnemy3::Num());
	mpUi->Render();
	mpUi->Over();
}

CGame2::~CGame2()
{
	//�S�ẴC���X�^���X�폜
	CApplication::CharacterManager()->AllDelete();
	//UI�𐶐����Ă��鎞
	if (mpUi != nullptr)
	{	//UI���폜���A������
		delete mpUi;
		mpUi = nullptr;
	}
}

bool CGame2::IsClear()
{
	return CEnemy3::Num() <= 0;
}

void CGame2::Clear()
{
	CameraSet();
	//�Q�[���̕`��
	CApplication::CharacterManager()->Render();
	CCamera::End();
	//UI����
	mpUi->Hp(CPlayer3::Hp());
	mpUi->Enemy(CEnemy3::Num());
	mpUi->Render();
	mpUi->Clear();
}

CGame2::CGame2()
	: mpUi(nullptr)
	, mTime(0)
	, mCdx(0)
	, mCdy(0)
{
	CEnemy3::Num(0);
	mpUi = new CUi();
	//�e�N�X�`���̓���
	CApplication::Texture()->Load(TEXTURE);

	//�萔�̒�`
	const int ROWS = 15; //�s��
	const int COLS = 20; //��
	//2�����z��̃}�b�v
	int map[ROWS][COLS] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3},
		{0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3,0,3},
		{0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4},
		{0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4,0,4},
		{0,5,0,5,0,5,0,5,0,5,0,5,0,5,0,5,0,5,0,5},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};

	//�}�b�v�̍쐬
	//�s�����J��Ԃ�
	for (int row = 0; row < ROWS; row++)
	{
		//�񐔕��J��Ԃ�
		for (int col = 0; col < COLS; col++)
		{
			//1�̎��A�u���b�N����
			if (map[row][col] == 1)
			{
				//�u���b�N�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CBlock(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture()));
			}
			//2�̎��A�v���C���[����
			if (map[row][col] == 2)
			{
				//�J�����p����
				mCdx = WINDOW_WIDTH / 4 - (TIPSIZE + TIPSIZE * 2 * col);
				mCdy = WINDOW_HEIGHT / 4 - (TIPSIZE + TIPSIZE * 2 * row);
				//�v���C���[�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					mpPlayer = new CPlayer3(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture3()));
			}
			//3�̎��A�G����
			if (map[row][col] == 3 || map[row][col] == 4 || map[row][col] == 5)
			{
				//�G�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CEnemy3(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CApplication::Texture3()));
			}
			//4�̎��A�܂�Ԃ��|�C���g�쐬
			if (map[row][col] == 4)
			{
				//�܂�Ԃ��|�C���g�𐶐����āA�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CPoint(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE, CCharacter::ETag::ETURN));
			}
		}
	}
}

void CGame2::Update()
{
	//�X�V�A�ՓˁA�폜�A�`��
	CApplication::CharacterManager()->Update();
	CApplication::CharacterManager()->Collision();
	CApplication::CharacterManager()->Delete();
//	CameraSet();
	CApplication::CharacterManager()->Render();
//	CCamera::End();
	//UI
	mpUi->Time(mTime++);
	mpUi->Hp(CPlayer2::Hp());
	mpUi->Enemy(CEnemy3::Num());
	mpUi->Render();
}

void CGame2::CameraSet()
{
	float x = mpPlayer->X() + mCdx;
	float y = mpPlayer->Y() + mCdy;
	CCamera::Start(x - WINDOW_WIDTH / 2
		, x + WINDOW_WIDTH / 2
		, y - WINDOW_HEIGHT / 2
		, y + WINDOW_HEIGHT / 2
	);
}
