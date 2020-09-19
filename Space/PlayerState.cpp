#include "stdafx.h"
#include "PlayerState.h"
#include"StateIdle.h"
#include"StateRun.h"
#include"StateJump.h"
#include"StateJumpRun.h"
#include"StateAppear.h"
#include"StateUnder.h"
#include"StateUp.h"
#include"StateShot.h"
#include"StateUpShot.h"
#include"StateUnderShot.h"
#include"StateDown.h"
#include"StateDownMove.h"
#include"StateDownShot.h"
#include"StateJumpShot.h"
#include"StateJumpRunShot.h"

StateIdle* PlayerState::m_Idle = new StateIdle();
StateRun* PlayerState::m_Run = new StateRun();
StateJump* PlayerState::m_Jump = new StateJump();
StateJumpRun* PlayerState::m_JumpRun = new StateJumpRun();
StateAppear* PlayerState::m_Appear = new StateAppear();
StateUnder* PlayerState::m_Under = new StateUnder();
StateUp* PlayerState::m_Up = new StateUp();
StateShot* PlayerState::m_Shot = new StateShot();
StateUpShot* PlayerState::m_UpShot = new StateUpShot();
StateUnderShot* PlayerState::m_UnderShot = new StateUnderShot();
StateDown* PlayerState::m_Down = new StateDown();
StateDownMove* PlayerState::m_DownMove = new StateDownMove();
StateDownShot* PlayerState::m_DownShot = new StateDownShot();
StateJumpShot* PlayerState::m_JumpShot = new StateJumpShot();
StateJumpRunShot* PlayerState::m_JumpRunShot = new StateJumpRunShot();

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
