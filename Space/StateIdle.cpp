#include "stdafx.h"
#include "StateIdle.h"
#include"StateJump.h"
#include"StateRun.h"
#include"StateUp.h"

StateIdle::StateIdle()
{
}

StateIdle::~StateIdle()
{
}

void StateIdle::Init(Player* player)
{
	if(player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"Stand.bmp", 0, 4, L"Painting/Player/Right/Bottom/Stand.bmp", 0, 1);
	else if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"Stand.bmp", 0, 4, L"Painting/Player/Left/Bottom/Stand.bmp", 0, 1);
}

void StateIdle::SetState(Player* player)
{
}

void StateIdle::Update(Player* player)
{
	if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS || INPUT->GetKey(VK_LEFT) == KeyState::PRESS)
	{
		player->m_State = PlayerState::m_Run;
		player->m_State->Init(player);
	}
	if (INPUT->GetKey('A') == KeyState::DOWN)
	{
		if (player->m_DistanceGround > 0)
		{
			player->m_Position.y -= player->m_DistanceGround;
		}

		player->m_JumpTime = 0.f;
		player->Pos = player->m_Position;
		player->m_State = PlayerState::m_Jump;
		player->m_State->Init(player);
	}
	if (INPUT->GetKey(VK_UP) == KeyState::PRESS)
	{
		player->m_State = m_Up;
		player->m_State->Init(player);
	}
}	