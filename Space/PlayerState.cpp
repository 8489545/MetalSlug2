#include "stdafx.h"
#include "PlayerState.h"
#include"StateIdle.h"

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
		player->m_State = new StateIdle();
		player->m_State->Init(player);
	}
}

void PlayerState::Update(Player* player)
{
}
