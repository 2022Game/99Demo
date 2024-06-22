#include "CGame.h"
#include "CApplication.h"
#include "CBlock.h"

CGame::CGame()
{
	//テクスチャの入力
	CApplication::Texture()->Load(TEXTURE);
	//ブロックを生成して、キャラクタマネージャに追加
	CApplication::CharacterManager()->Add(
		new CBlock(400.0f, 300.0f, TIPSIZE, TIPSIZE,
			CApplication::Texture()));
}

void CGame::Update()
{
	//更新、衝突、削除、描画
	CApplication::CharacterManager()->Update();
	CApplication::CharacterManager()->Collision();
	CApplication::CharacterManager()->Delete();
	CApplication::CharacterManager()->Render();
}
