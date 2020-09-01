#include "stdafx.h"
#include "StateRun.h"
#include "StateIdle.h"
#include"StateJump.h"

StateRun::StateRun()
{
}

StateRun::~StateRun()
{
}

void StateRun::Init(Player* player)
{
	if(player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"Run.bmp", 0, 12, L"Painting/Player/Right/Bottom/Run.bmp", 0, 12);
	if(player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"Run.bmp", 0, 12, L"Painting/Player/Left/Bottom/Run.bmp", 0, 12);
}

void StateRun::SetState(Player* player)
{
}

void StateRun::Update(Player* player)
{
	player->Move();
	if (INPUT->GetKey(VK_RIGHT) == KeyState::UP || INPUT->GetKey(VK_LEFT) == KeyState::UP)
	{
		player->m_State = PlayerState::m_Idle;
		player->m_State->Init(player);
	}
	if (INPUT->GetKey('A') == KeyState::DOWN)
	{
		player->m_JumpTime = 0.f;
		player->Pos = player->m_Position;
		player->m_State = PlayerState::m_Jump;
		player->m_State->Init(player);
	}
}
