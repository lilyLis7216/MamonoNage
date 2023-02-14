#pragma once
#include"DxLib.h"

class EffectMgr final
{
public:
	static void CreateInstance();
	static void DeleteInstance();
	static void ADraw(int offsetX, int offsetY);
	/// <summary>
	/// A�̃G�t�F�N�g�֘A
	/// </summary>
	static int Ax;
	static int Ay;
	static int AXNum;
	static int AYNum;
	static int AXSize;
	static int AYSize;
	static int AHandle;
	static float AEffectTime;
	static int AEffect;
	static int AEffectAnimation[10];
	static bool AEffectFlag;
	static void SetAEffectFlag(bool flag);//�G�t�F�N�g�t���O��������
	static void EffectA(float _deltaTime, int x, int y);
	


private:
	EffectMgr();
	~EffectMgr();
	static EffectMgr* mpInstance;
};

