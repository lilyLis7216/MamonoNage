#include "Flag.h"
#include"../../Collision/Collision.h"
#include"../../Collision/MapCollision.h"

Flag::Flag()
	:GameObj(ObjTag::Flag)
{	
	pos.x = 500;
	pos.y = 670;
	handle = LoadGraph("../asset/player/Door.png");
}

Flag::~Flag()
{
	handle = -1;
}

void Flag::Update(float _deltaTime)
{
	
}	

void Flag::Draw(int offSetX, int offSetY)
{
	DrawRotaGraph(pos.x-offSetX, pos.y-offSetY, 3,0,handle, TRUE);
}

void Flag::OnCollisionEnter(GameObj* other)
{
}
