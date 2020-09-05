#include "stdafx.h"
#include "StateShot.h"
#include"StateIdle.h"

StateShot::StateShot()
{
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
}

void StateShot::Update(Player* player)
{
	if (player->m_JumpAccel > 0.f)
	{
		player->Jump();
		player->JumpRun();
	}
	if (player->m_Top->m_CurrentFrame > 5)
	{
		if (INPUT->GetKey('S') == KeyState::DOWN)
		{
			player->m_State = m_Shot;
			player->m_State->Init(player);
		}
	}
	if (player->m_Top->m_CurrentFrame == 8)
	{
		player->m_State = m_Idle;
		player->m_State->Init(player);
	}

	if (player->m_isGround)
	{
		player->m_JumpAccel = 0.f;
	}
}
