#include "stdafx.h"
#include "StateUnder.h"
#include"StateIdle.h"
#include"StateJump.h"

StateUnder::StateUnder()
{
}

StateUnder::~StateUnder()
{
}

void StateUnder::Init(Player* player)
{
	if (player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"Under.bmp", 0, 1, L"Painting/Player/Right/Bottom/Jump.bmp", 0, 6);
	if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"Under.bmp", 0, 1, L"Painting/Player/Left/Bottom/Jump.bmp", 0, 6);

	Dire = player->m_Dire;
}

void StateUnder::Update(Player* player)
{
	if (Dire != player->m_Dire)
		Init(player);

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

	if (INPUT->GetKey(VK_DOWN) == KeyState::UP)
	{
		player->m_State = PlayerState::m_Jump;
		player->m_State->Init(player);
	}

	if (player->m_isGround && m_isFalled)
	{
		m_isJump = false;
		player->m_State = PlayerState::m_Idle;
		player->m_State->Init(player);
	}
}
