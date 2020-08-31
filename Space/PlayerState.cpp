#include "stdafx.h"
#include "PlayerState.h"
#include"StateIdle.h"
#include"StateRun.h"

PlayerState::PlayerState()
{
}

PlayerState::~PlayerState()
{
}

void PlayerState::Init(Player* player)
{
}

void PlayerState::SetState(Player* player, State state)
{
	if (state == State::IDLE)
	{
		//player->m_State = m_Idle;
		player->m_State->Init(player);
	}
}

void PlayerState::Update(Player* player)
{
}
