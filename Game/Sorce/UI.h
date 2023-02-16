#pragma once

#include"DxLib.h"
#include"Manager/BulletMgr.h"


class UI final
{
public:
	
	static void CreateInstance();
	static void DeleteInstance();

	static void UIBox(int x1, int x2, int y1, int y2, int frameSize, int mainCr, int frameCr);
	static void UIText(int x, int y, int color, const char* str);
	static void ReadyBullet(BulletMgr::BulletType type);
	static void GoastBulletCoolTime(float cooltime);


	static void Draw(BulletMgr::BulletType type);
private:

	UI();
	~UI();
	static UI* mpInstance;

	/*static VECTOR ReadyBulletUI;*/
	static int ReadyBulletBoxX1;
	static int ReadyBulletBoxY1;
	static int ReadyBulletBoxX2;
	static int ReadyBulletBoxY2;
	static int ReadyBulletBoxFlameSize;
	static int ReadyBulletBoxmainCr;
	static int ReadyBulletBoxframeCr;

	static int ReadyBulletPosX;
	static int ReadyBulletPosY;
	static int GoastBulletCoolTimeR;
};

