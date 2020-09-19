#include "stdafx.h"
#include "StateShot.h"
#include"StateIdle.h"

StateShot::StateShot()
{
	m_Timer = 0.f;
	m_isShot = false;
}

StateShot::~StateShot()
{
}

void StateShot::Init(Player* player)
{
	if (player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"Shot.bmp", 0, 9, L"Painting/Player/Right/Bottom/Stand.bmp", 0, 1);
	if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"Shot.bmp", 0, 9, L"Painting/Player/Left/Bottom/Stand.bmp", 0, 1);
	
	m_isShot = false;
}

void StateShot::Update(Player* player)
{
	m_Timer += dt;
	if (player->m_Top->m_CurrentFrame == 1 && !m_isShot)
	{
		if (player->m_Dire == RIGHT)
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Att/Pistol.bmp", Vec2((player->m_Position.x + 1000), player->m_Position.y),
				Vec2(player->m_Position.x + 30,player->m_Position.y + 40), 800.f), "pBullet");
		else if (player->m_Dire == LEFT)
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Att/Pistol.bmp", Vec2((player->m_Position.x - 1000), player->m_Position.y),
				Vec2(player->m_Position.x - 30, player->m_Position.y + 40), 800.f), "pBullet");

		m_isShot = true;
	}

	if (m_Timer >= 0.49f)
	{
		m_Timer = 0.f;
		player->m_State = PlayerState::m_Idle;
		player->m_State->Init(player);
	}


	if (player->m_Top->m_CurrentFrame >= 5)
	{
		if (INPUT->GetKey('S') == KeyState::DOWN)
		{
			m_Timer = 0.f;
			player->m_JumpTime = 0.f;
			player->m_State = m_Shot;
			player->m_State->Init(player);
		}
	}
}
