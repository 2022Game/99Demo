#include "CApplication.h"
#include "CRectangle.h"

//クラスのstatic変数
CTexture CApplication::mTexture;
CCharacterManager CApplication::mCharacterManager;

#define SOUND_BGM "res\\mario.wav" //BGM音声ファイル
#define SOUND_OVER "res\\mdai.wav" //ゲームオーバー音声ファイル

CCharacterManager* CApplication::CharacterManager()
{
	return &mCharacterManager;
}

CTexture* CApplication::Texture()
{
	return &mTexture;
}

//テクスチャファイル名
#define TEXTURE2 "22302021.png"
CTexture CApplication::mTexture2;
CTexture* CApplication::Texture2()
{
	return &mTexture2;
}

//テクスチャファイル名
#define TEXTURE3 "117159.png"
CTexture CApplication::mTexture3;
CTexture* CApplication::Texture3()
{
	return &mTexture3;
}

void CApplication::Start()
{
	mTexture3.Load(TEXTURE3);
	mTexture2.Load(TEXTURE2);
	//Sound
	mSoundBgm.Load(SOUND_BGM);
	mSoundOver.Load(SOUND_OVER);

	mFont.Load("FontWhite.png", 1, 64);
	mState = EState::ESTART;
	mpGame = new CGame2();
}

void CApplication::Update()
{
	switch (mState)
	{
	case EState::ESTART:	//状態がスタート
		mpGame->Start();	//スタート画面表示
		//Enterキーが押されたら
		if (mInput.Key(VK_RETURN)
			|| mInput.Key(VK_LBUTTON))
		{	//状態をプレイ中にする
			mState = EState::EPLAY;
			//BGMリピート再生
			mSoundBgm.Repeat();
		}
		break;
	case EState::EPLAY:
		mpGame->Update();
		//ゲームオーバーか判定
		if (mpGame->IsOver())
		{	//状態をゲームオーバーにする
			mState = EState::EOVER;
			//BGMストップ
			mSoundBgm.Stop();
			//ゲームオーバー
			mSoundOver.Play();
		}
		//ゲームクリアか判定
		if (mpGame->IsClear())
		{	//状態をゲームクリアにする
			mState = EState::ECLEAR;
		}
		break;
	case EState::EOVER:
		//ゲームオーバー処理
		mpGame->Over();
		//エンターキー入力時
		if (mInput.Key(VK_RETURN))
		{	//ゲームのインスタンス削除
			delete mpGame;
			//ゲームのインスタンス生成
			mpGame = new CGame2();
			//状態をスタートにする
			mState = EState::ESTART;
		}
		break;
	case EState::ECLEAR:
		//ゲームクリア処理
		mpGame->Clear();
		if (mInput.Key(VK_RETURN))
		{
			delete mpGame;
			mpGame = new CGame2();
			mState = EState::ESTART;
		}
		break;
	}
}
