#include "stdafx.h"
#include "StateJumpRunBomb.h"
#include"Bomb.h"
#include"StateJump.h"
#include"StateIdle.h"

StateJumpRunBomb::StateJumpRunBomb()
{
}

StateJumpRunBomb::~StateJumpRunBomb()
{
}

void StateJumpRunBomb::Init(Player* player)
{
	if (player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"bomb.bmp", 0, 6, L"Painting/Player/Right/Bottom/Jump.bmp", 0, 6);
	if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"bomb.bmp", 0, 6, L"Painting/Player/Left/Bottom/Jump.bmp", 0, 6);

	m_Timer = 0.f;

	ObjMgr->AddObject(new Bomb(player->m_Position, player->m_Dire), "Bomb");
}

void StateJumpRunBomb::Update(Player* player)
{
	m_Timer += dt;
	m_isJump = true;

	if (m_isJump)
	{
		m_PrevPos = player->m_Position;
		player->Jump();
		player->JumpRun();

		if (m_PrevPos.y < player->m_Position.y)
			m_isFalled = true;
		else
			m_isFalled = false;
	}

	if (m_Timer >= 0.49f)
	{
		m_Timer = 0.f;
		player->m_State = PlayerState::m_Jump;
		player->m_State->Init(player);
	}

	if (player->m_isGround && m_isFalled)
	{
		m_isJump = false;
		player->m_State = PlayerState::m_Idle;
		player->m_State->Init(player);
	}


	if (player->m_Top->m_CurrentFrame >= 3)
	{
		if (INPUT->GetKey('D') == KeyState::DOWN)
		{
			player->m_State = m_JumpRunBomb;
			player->m_State->Init(player);
		}
	}

	if (player->m_isGround)
	{
		player->m_JumpAccel = 0.f;
	}
}
