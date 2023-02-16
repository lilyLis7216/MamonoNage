	#include "UI.h"

	UI* UI::mpInstance = nullptr;

	int UI::ReadyBulletBoxX1 = 0;
	int UI::ReadyBulletBoxY1 = 400;
	int UI::ReadyBulletBoxX2 = 800;
	int UI::ReadyBulletBoxY2 = 1080;
	int UI::ReadyBulletBoxFlameSize = 10;
	int UI::ReadyBulletBoxmainCr = 0;
	int UI::ReadyBulletBoxframeCr = 0;

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

		DrawRotaGraph(70,980,4.0f,0,BulletMgr::GetHandle(),TRUE);
	}

	void UI::Draw(BulletMgr::BulletType type)
	{
		UIBox(ReadyBulletBoxX1, ReadyBulletBoxY1, ReadyBulletBoxX2, ReadyBulletBoxY2, ReadyBulletBoxFlameSize,ReadyBulletBoxmainCr, ReadyBulletBoxframeCr);
		ReadyBullet(type);
	}