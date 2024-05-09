#pragma once
class CRectangle
{
public:
	CRectangle();
	~CRectangle();
	void Render();
	void Render(float x, float y, float w, float h);
	void Set(float x, float y, float w, float h);
	float X();
	float Y();
	float W();
	float H();
	void X(float x);
	void Y(float y);
	//bool Collision(�l�p�`�̃|�C���^)
	//�߂�l
	//true:�Փ˂��Ă���
	//false;�Փ˂��Ă��Ȃ�
	bool Collision(CRectangle* pRect);

private:
	float mX; //X���W
	float mY; //Y���W
	float mW; //��
	float mH; //����
};