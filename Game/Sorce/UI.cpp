	#include "UI.h"
	#include"DxLib.h"
	UI* UI::mpInstance = nullptr;

	int UI::ReadyBulletBoxX1 = 0;
	int UI::ReadyBulletBoxY1 = 300;
	int UI::ReadyBulletBoxX2 = 780;
	int UI::ReadyBulletBoxY2 = 1080;
	int UI::ReadyBulletBoxFlameSize = 10;
	int UI::ReadyBulletBoxmainCr = 0;
	int UI::ReadyBulletBoxframeCr = 0;

	int UI::ReadyBulletPosX=130;
	int UI::ReadyBulletPosY=980;
	int UI::GoastBulletCoolTimeR=30;


	UI::UI()
	{
		mpInstance = nullptr;
	}

	UI::~UI()
	{
		mpInstance = nullptr;
	}

	void UI::CreateInstance()
	{
		if (!mpInstance)
		{
			mpInstance = new UI;
		}
	}
	void UI::DeleteInstance()
	{
	}
	void UI::UIBox(int x1, int x2, int y1, int y2, int frameSize, int mainCr, int frameCr)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);// ベース
		DrawBox(x1, y1, x2, y2, mainCr, TRUE);// 上辺
		DrawLine(x1 + frameSize, y1 + frameSize / 2, x2 - frameSize, y1 + frameSize / 2, frameCr, frameSize);// 下辺
		DrawLine(x1 + frameSize, y2 - frameSize / 2, x2 - frameSize, y2 - frameSize / 2, frameCr, frameSize);// 左辺
		DrawLine(x1 + frameSize / 2, y1, x1 + frameSize / 2, y2, frameCr, frameSize);// 右辺
		DrawLine(x2 - frameSize / 2, y1, x2 - frameSize / 2, y2, frameCr, frameSize);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	void UI::UIText(int x, int y, int color, const char* str)
	{

	}

	void UI::ReadyBullet(BulletMgr::BulletType type)
	{

		DrawRotaGraph(ReadyBulletPosX, ReadyBulletPosY,5.0f,0,BulletMgr::GetHandle(),TRUE);
	}

	void UI::GoastBulletCoolTime(float cooltime)
	{
		int x = 40; // バーのx座標
		int y = 850; // バーのy座標
		int w = 200; // バーの幅
		int h = 50;  // バーの高さ

		// バーの輪郭を描画
		DrawBox(x, y, x + w, y + h, GetColor(255, 255, 255), FALSE);

		// バーの内部を描画（クールタイムが経過した割合で塗りつぶす）
		int barWidth = (cooltime > 0) ? (w * (cooltime / 3)) : w;
		int barColor = (cooltime > 0) ? GetColor(255, 255, 255) : GetColor(255, 255, 255);
		DrawBox(x, y, x + barWidth, y + h, barColor, TRUE);
	}


	void UI::Draw(BulletMgr::BulletType type)
	{
		UIBox(ReadyBulletBoxX1, ReadyBulletBoxY1, ReadyBulletBoxX2, ReadyBulletBoxY2, ReadyBulletBoxFlameSize,ReadyBulletBoxmainCr, ReadyBulletBoxframeCr);
		ReadyBullet(type);
		if (BulletMgr::GetHandle() == BulletMgr::GetGoastHandle()&& BulletMgr::GoastCoolTime<3.0f) {
			GoastBulletCoolTime(BulletMgr::GoastCoolTime);
		}
	}
