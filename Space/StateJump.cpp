#include "stdafx.h"
#include "StateJump.h"
#include"StateIdle.h"
#include"StateJumpRun.h"
#include"StateUnder.h"
#include"StateJumpShot.h"

StateJump::StateJump() : m_PrevPos(0, 0), m_isFalled(false), m_isJump(false)
{
}

StateJump::~StateJump()
{
}

void StateJump::Init(Player* player)
{
	if (player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"Jump.bmp", 0, 6, L"Painting/Player/Right/Bottom/Jump.bmp", 0, 6);
	if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"Jump.bmp", 0, 6, L"Painting/Player/Left/Bottom/Jump.bmp", 0, 6);
}
void StateJump::Update(Player* player)
{
	m_isJump = true;

	if (m_isJump)
	{
		m_PrevPos = player->m_Position;
		player->Jump();

		if (m_PrevPos.y < player->m_Position.y)
			m_isFalled = true;
		else
			m_isFalled = false;
	}
	if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS || INPUT->GetKey(VK_LEFT) == KeyState::PRESS)
	{
		player->m_State = PlayerState::m_JumpRun;
		player->m_State->Init(player);
	}
	if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS)
	{
		player->m_State = PlayerState::m_Under;
		player->m_State->Init(player);
	}

	if (player->m_isGround && m_isFalled)
	{
		m_isJump = false;
		player->m_State = PlayerState::m_Idle;
		player->m_State->Init(player);
	}

	if (INPUT->GetKey('S') == KeyState::DOWN)
	{
		player->m_State = m_JumpShot;
		player->m_State->Init(player);
	}
}
