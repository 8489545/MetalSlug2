#include "stdafx.h"
#include "StateJumpRun.h"
#include"StateIdle.h"

StateJumpRun::StateJumpRun()
{
}

StateJumpRun::~StateJumpRun()
{
}

void StateJumpRun::Init(Player* player)
{
	if (player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"Jump_run.bmp", 0, 6, L"Painting/Player/Right/Bottom/Jump_run.bmp", 0, 6);
	if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"Jump_run.bmp", 0, 6, L"Painting/Player/Left/Bottom/Jump_run.bmp", 0, 6);
}

void StateJumpRun::Update(Player* player)
{
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

	if (player->m_isGround && m_isFalled)
	{
		m_isJump = false;
		player->m_State = PlayerState::m_Idle;
		player->m_State->Init(player);
	}
}
