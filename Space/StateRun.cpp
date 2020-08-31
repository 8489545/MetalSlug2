#include "stdafx.h"
#include "StateRun.h"
#include "StateIdle.h"

StateRun::StateRun()
{
}

StateRun::~StateRun()
{
}

void StateRun::Init(Player* player)
{
	if(player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/Run.bmp", 0, 12, L"Painting/Player/Right/Bottom/Run.bmp", 0, 12);
	if(player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/Run.bmp", 0, 12, L"Painting/Player/Left/Bottom/Run.bmp", 0, 12);
}

void StateRun::SetState(Player* player, State state)
{
}

void StateRun::Update(Player* player)
{
	if (INPUT->GetKey(VK_RIGHT) == KeyState::UP || INPUT->GetKey(VK_LEFT) == KeyState::UP)
	{
		//player->m_State = new StateIdle();
		player->m_State->Init(player);
	}
}
