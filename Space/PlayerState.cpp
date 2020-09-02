#include "stdafx.h"
#include "PlayerState.h"
#include"StateIdle.h"
#include"StateRun.h"
#include"StateJump.h"
#include"StateJumpRun.h"
#include"StateAppear.h"

StateIdle* PlayerState::m_Idle = new StateIdle();
StateRun* PlayerState::m_Run = new StateRun();
StateJump* PlayerState::m_Jump = new StateJump();
StateJumpRun* PlayerState::m_JumpRun = new StateJumpRun();
StateAppear* PlayerState::m_Appear = new StateAppear();

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
	player->m_State = m_Appear;
	player->m_State->Init(player);
}

void PlayerState::Update(Player* player)
{
}
