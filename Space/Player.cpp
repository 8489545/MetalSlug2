#include "stdafx.h"
#include "Player.h"
#include"Texture.h"
#include"PlayerState.h"

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


void Player::ChangeImage(std::wstring top, int topfirst, int toplast, std::wstring bottom, int bottomfirst, int bottomlast)
{
	if (m_Top)
		ObjMgr->RemoveObject(m_Top);
	if (m_Bottom)
		ObjMgr->RemoveObject(m_Bottom);

	m_Top = new Animation();
	m_Top->Init(0.1f, true, BigImage);
	m_Top->AddContinueFrame(top, topfirst, toplast, COLORKEY_SKY);

	m_Bottom = new Animation();
	m_Bottom->Init(0.1f, true, BigImage);
	m_Bottom->AddContinueFrame(bottom, bottomfirst, bottomlast, COLORKEY_SKY);
}

void Player::ChangeImage(std::wstring body, int first, int last)
{
	if (m_Body)
		ObjMgr->RemoveObject(m_Body);

	m_Body = new Animation();
	m_Body->Init(0.1f, true, BigImage);
	m_Body->AddContinueFrame(body, first, last, COLORKEY_SKY);
}

void Player::Update(float deltaTime, float Time)
{
	if (!m_isGround)
	{
		m_vY += 9.8f * dt;
		m_Position.y += m_vY;
	}
	Move();
}

void Player::Render()
{
	m_Player->Render();
}

void Player::Move()
{
	int pos = (int)(m_Position.y + m_Size.y) * Game::GetInst()->GetCollisionMapRect().Pitch / 4 + (int)(m_Position.x + m_Size.x / 2);
	D3DXCOLOR color = Game::GetInst()->GetMapColor(pos);

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
		int lpos = (int)((m_Position.y - m_WeightY - 1) + m_Size.y) * Game::GetInst()->GetCollisionMapRect().Pitch / 4 + (int)((m_Position.x - 1) + m_Size.x / 2);
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
		int rpos = (int)((m_Position.y - m_WeightY - 1) + m_Size.y) * Game::GetInst()->GetCollisionMapRect().Pitch / 4 + (int)((m_Position.x + 1) + m_Size.x / 2);
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
