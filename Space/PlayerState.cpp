#include "stdafx.h"
#include "PlayerState.h"
#include"StateIdle.h"
#include"StateRun.h"
#include"StateJump.h"

StateIdle* PlayerState::m_Idle = new StateIdle();
StateRun* PlayerState::m_Run = new StateRun();
StateJump* PlayerState::m_Jump = new StateJump();

PlayerState::PlayerState()
{
}

PlayerState::~PlayerState()
{
}

void PlayerState::Init(Player* player)
{
}

void PlayerState::SetState(Player* player)
{
	player->m_State = PlayerState::m_Idle;
	player->m_State->Init(player);
}

void PlayerState::Update(Player* player)
{
}
