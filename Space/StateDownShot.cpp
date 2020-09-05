#include "stdafx.h"
#include "StateDownShot.h"
#include"StateDown.h"

StateDownShot::StateDownShot()
{
}

StateDownShot::~StateDownShot()
{
}

void StateDownShot::Init(Player* player)
{
	if (player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"down_shot.bmp", 0, 5, L"Painting/Player/Right/Top/" + player->m_Weapon + L"down_shot.bmp", 0, 5);
	else if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"down_shot.bmp", 0, 5, L"Painting/Player/Left/Top/" + player->m_Weapon + L"down_shot.bmp", 0, 5);
}

void StateDownShot::Update(Player* player)
{
	if (player->m_Top->m_CurrentFrame == 1)
	{
		player->m_Top->m_CurrentFrame += 1;

		if (player->m_Dire == RIGHT)
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Att/Pistol.bmp", Vec2((player->m_Position.x + 1000), player->m_Position.y),
				Vec2(player->m_Position.x, player->m_Position.y + 70), 800.f), "pBullet");
		else if (player->m_Dire == LEFT)
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Att/Pistol.bmp", Vec2((player->m_Position.x - 1000), player->m_Position.y),
				Vec2(player->m_Position.x, player->m_Position.y + 70), 800.f), "pBullet");
	}
	if (player->m_Top->m_CurrentFrame > 3)
	{
		if (INPUT->GetKey('S') == KeyState::DOWN)
		{
			player->m_State = m_DownShot;
			player->m_State->Init(player);
		}
	}
	if (player->m_Top->m_CurrentFrame == 5)
	{
		player->m_State = m_Down;
		player->m_State->Init(player);
	}
}
