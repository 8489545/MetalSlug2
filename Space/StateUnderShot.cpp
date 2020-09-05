#include "stdafx.h"
#include "StateUnderShot.h"
#include"StateIdle.h"
#include"StateUnder.h"

StateUnderShot::StateUnderShot()
{
}

StateUnderShot::~StateUnderShot()
{
}

void StateUnderShot::Init(Player* player)
{
	if (player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"Under_Shot.bmp", 0, 4, L"Painting/Player/Right/Bottom/Jump.bmp", 0, 6);
	if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"Under_Shot.bmp", 0, 4, L"Painting/Player/Left/Bottom/Jump.bmp", 0, 6);
	Dire = player->m_Dire;
}

void StateUnderShot::Update(Player* player)
{
	if (Dire != player->m_Dire)
		Init(player);

	if (player->m_Top->m_CurrentFrame == 1)
	{
		player->m_Top->m_CurrentFrame += 1;

		if (player->m_Dire == RIGHT)
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Att/Pistol.bmp", Vec2((player->m_Position.x), player->m_Position.y + 1000),
				Vec2(player->m_Position.x + 30, player->m_Position.y + 50), 800.f), "pBullet");
		else if (player->m_Dire == LEFT)
			ObjMgr->AddObject(new Bullet(L"Painting/Player/Att/Pistol.bmp", Vec2((player->m_Position.x), player->m_Position.y + 1000),
				Vec2(player->m_Position.x + 30, player->m_Position.y + 50), 800.f), "pBullet");
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

	if (player->m_Top->m_CurrentFrame > 3)
	{
		if (INPUT->GetKey('S') == KeyState::DOWN)
		{

			player->m_State = m_UnderShot;
			player->m_State->Init(player);
		}
	}
	if (player->m_Top->m_CurrentFrame == 3)
	{
		player->m_State = m_Under;
		player->m_State->Init(player);
	}

	if (player->m_isGround)
	{
		player->m_JumpAccel = 0.f;
	}
}
