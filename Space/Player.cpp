#include "stdafx.h"
#include "Player.h"
#include"Texture.h"

Player::Player(Vec2 Pos)
{
	m_Player = Sprite::Create(L"Painting/Player.png");
	m_Player->SetParent(this);

	SetPosition(800 / 2, 600 / 2);


	

	m_isGround = false;
	m_WeightY = 0;
	m_vY = 0.f;

	m_Speed = 150.f;
}

Player::~Player()
{
}


void Player::Update(float deltaTime, float Time)
{
	if (!m_isGround)
	{
		m_vY += 9.8f * dt;
		m_Position.y += m_vY;
	}

	int pos = (int)(m_Position.y + m_Size.y / 2) * Game::GetInst()->GetCollisionMapRect().Pitch / 4 + (int)(m_Position.x + m_Size.x / 2);
	D3DXCOLOR color = Game::GetInst()->GetMapColor(pos);

	printf("%d \n", m_WeightY);
	if (color.r == 1.f && color.g == 0 && color.b == 1.f)
	{
		m_isGround = true;
		m_vY = 0.f;
	}
	else
	{
		m_isGround = false;
	}
	if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS)
	{
		int lpos = (int)((m_Position.y - m_WeightY - 1) + m_Size.y / 2) * Game::GetInst()->GetCollisionMapRect().Pitch / 4 + (int)((m_Position.x - 1) + m_Size.x / 2);
		D3DXCOLOR lcolor = Game::GetInst()->GetMapColor(lpos);

		if (lcolor.r == 0.f && lcolor.g == 0 && lcolor.b == 0.f)
		{
			m_Position.x -= m_Speed * dt;
			m_Position.y -= m_WeightY;
			m_WeightY = 0;
		}
		else
		{
			m_WeightY++;
		}
	}
	if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS)
	{
		int rpos = (int)((m_Position.y - m_WeightY - 1) + m_Size.y / 2) * Game::GetInst()->GetCollisionMapRect().Pitch / 4 + (int)((m_Position.x + 1) + m_Size.x / 2);
		D3DXCOLOR rcolor = Game::GetInst()->GetMapColor(rpos);

		if (rcolor.r == 0.f && rcolor.g == 0 && rcolor.b == 0.f)
		{
			m_Position.x += m_Speed * dt;
			m_Position.y -= m_WeightY;
			m_WeightY = 0;
		}
		else
		{
			m_WeightY++;
		}
	}
}

void Player::Render()
{
	m_Player->Render();
}
