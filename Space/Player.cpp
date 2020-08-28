#include "stdafx.h"
#include "Player.h"
#include"Texture.h"

Player::Player(Vec2 Pos)
{
	m_Player = Sprite::Create(L"Painting/Player.png");
	m_Player->SetParent(this);

	SetPosition(800 / 2, 600 / 2);


	D3DLOCKED_RECT LockRect;
	ZeroMemory(&LockRect, sizeof(LockRect));
	((Sprite*)ObjMgr->FindObject("CMap"))->GetSpriteTexture()->GetTexture()->LockRect(0, &LockRect, 0, 0);

	m_MapColor = (DWORD*)LockRect.pBits;
	MapPitch = LockRect.Pitch;
	int width = ((Sprite*)ObjMgr->FindObject("CMap"))->m_Size.x;
	MapWidth = width;
	((Sprite*)ObjMgr->FindObject("CMap"))->GetSpriteTexture()->GetTexture()->UnlockRect(0);

	m_isGround = false;
	m_WeightY = 0;
	m_vY = 0.f;

	m_Speed = 100.f;
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

	int pos = (int)(m_Position.y + m_Size.y / 2) * MapPitch / 4 + (int)(m_Position.x + m_Size.x / 2);
	D3DXCOLOR color = m_MapColor[pos];

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
		int lpos = (int)((m_Position.y - m_WeightY) + m_Size.y / 2) * MapPitch / 4 + (int)((m_Position.x - 1) + m_Size.x / 2);
		D3DXCOLOR lcolor = m_MapColor[lpos];

		if (lcolor.r == 0.f && lcolor.g == 0 && lcolor.b == 0.f)
		{
			m_Position.x -= 100 * dt;
			m_Position.y -= m_WeightY;
			m_WeightY = 0;
		}
		else
		{
			m_WeightY += 1;
		}

		m_Position.x -= m_Speed * dt;
	}
	if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS)
	{
		int rpos = (int)((m_Position.y - m_WeightY) + m_Size.y / 2) * MapPitch / 4 + (int)((m_Position.x + 1) + m_Size.x / 2);
		D3DXCOLOR rcolor = m_MapColor[rpos];

		if (rcolor.r == 0.f && rcolor.g == 0 && rcolor.b == 0.f)
		{
			m_Position.x += 100 * dt;
			m_Position.y -= m_WeightY;
			m_WeightY = 0;
		}
		else
		{
			m_WeightY += 1;
		}
	
		m_Position.x += m_Speed * dt;
	}
}

void Player::Render()
{
	m_Player->Render();
}
