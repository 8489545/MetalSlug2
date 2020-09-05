#include "stdafx.h"
#include "StateUpShot.h"
#include"StateIdle.h"

StateUpShot::StateUpShot()
{
}

StateUpShot::~StateUpShot()
{
}

void StateUpShot::Init(Player* player)
{
	if (player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"Up_Shot.bmp", 0, 10, L"Painting/Player/Right/Bottom/Stand.bmp", 0, 1);
	if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"Up_Shot.bmp", 0, 10, L"Painting/Player/Left/Bottom/Stand.bmp", 0, 1);
}

void StateUpShot::Update(Player* player)
{
	if (player->m_Top->m_CurrentFrame == 1)
	{
		player->m_Top->m_CurrentFrame += 1;

		if (player->m_Dire == RIGHT)
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Att/Pistol.bmp", Vec2((player->m_Position.x), player->m_Position.y - 100),
				Vec2(player->m_Position.x, player->m_Position.y ), 800.f), "pBullet");
		else if (player->m_Dire == LEFT)
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Att/Pistol.bmp", Vec2((player->m_Position.x), player->m_Position.y - 100),
				Vec2(player->m_Position.x, player->m_Position.y), 800.f), "pBullet");
	}
	if (player->m_Top->m_CurrentFrame > 5)
	{
		if (INPUT->GetKey('S') == KeyState::DOWN)
		{
			player->m_State = m_UpShot;
			player->m_State->Init(player);
		}
	}
	if (player->m_Top->m_CurrentFrame == 9)
	{
		player->m_State = m_Idle;
		player->m_State->Init(player);
	}

	if (player->m_isGround)
	{
		player->m_JumpAccel = 0.f;
	}
}
