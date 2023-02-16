#include "Flag.h"
#include"../../Collision/Collision.h"
#include"../../Collision/MapCollision.h"

Flag::Flag()
	:GameObj(ObjTag::Flag)
{	
	pos.x = 800;
	pos.y = 600;
	handle = LoadGraph("../asset/player/flag.jpg");
}

Flag::~Flag()
{
}

void Flag::Update(float _deltaTime)
{
	
}	

void Flag::Draw(int offSetX, int offSetY)
{
	DrawRotaGraph(pos.x-offSetX, pos.y-offSetY, 0.1,0,handle, TRUE);
}

void Flag::OnCollisionEnter(GameObj* other)
{
}
