#include "stdafx.h"
#include "StateJumpRunShot.h"
#include"StateJumpRun.h"
#include"StateIdle.h"

StateJumpRunShot::StateJumpRunShot()
{
	m_isShot = false;
}

StateJumpRunShot::~StateJumpRunShot()
{
}

void StateJumpRunShot::Init(Player* player)
{
	if (player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"Shot.bmp", 0, 9, L"Painting/Player/Right/Bottom/run.bmp", 0, 12);
	if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"Shot.bmp", 0, 9, L"Painting/Player/Left/Bottom/run.bmp", 0, 12);

	m_Timer = 0;

	m_isShot = false;
}

void StateJumpRunShot::Update(Player* player)
{
	m_Timer += dt;

	if (player->m_Top->m_CurrentFrame == 1 && !m_isShot)
	{
		if (player->m_Dire == RIGHT)
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Att/Pistol.bmp", Vec2((player->m_Position.x + 1000), player->m_Position.y),
				Vec2(player->m_Position.x + 30, player->m_Position.y + 40), 800.f), "pBullet");
		else if (player->m_Dire == LEFT)
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Att/Pistol.bmp", Vec2((player->m_Position.x - 1000), player->m_Position.y),
				Vec2(player->m_Position.x - 30, player->m_Position.y + 40), 800.f), "pBullet");

		m_isShot = true;
	}
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
		player->m_State = PlayerState::m_JumpRun;
		player->m_State->Init(player);
	}

	if (player->m_isGround && m_isFalled)
	{
		m_isJump = false;
		player->m_State = PlayerState::m_Idle;
		player->m_State->Init(player);
	}


	if (player->m_Top->m_CurrentFrame >= 5)
	{
		if (INPUT->GetKey('S') == KeyState::DOWN)
		{
			player->m_State = m_JumpRunShot;
			player->m_State->Init(player);
		}
	}

	if (player->m_isGround)
	{
		player->m_JumpAccel = 0.f;
	}
}
