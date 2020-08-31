#include "stdafx.h"
#include "PlayerState.h"
#include"StateIdle.h"
#include"StateRun.h"

StateIdle* PlayerState::m_Idle = new StateIdle();
StateRun* PlayerState::m_Run = new StateRun();

PlayerState::PlayerState()
{
}

PlayerState::~PlayerState()
{
}

void PlayerState::Init(Player* player, std::wstring weapon)
{
}

void PlayerState::SetState(Player* player, State state)
{
	if (state == State::IDLE)
	{
		player->m_State = m_Idle;
		player->m_State->Init(player);
	}
}

void PlayerState::Update(Player* player)
{
}
