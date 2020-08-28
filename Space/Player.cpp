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
}

Player::~Player()
{
}


void Player::Update(float deltaTime, float Time)
{
	if (!m_isGround)
	{
		m_Position.y += 100 * dt;
	}

	int pos = (int)(m_Position.y + m_Size.y / 2) * MapPitch / 4 + (int)(m_Position.x + m_Size.x / 2);
	D3DXCOLOR color = m_MapColor[pos];

	if (color.r == 1.f && color.g == 0 && color.b == 1.f)
	{
		m_isGround = true;
	}
	else
	{
		m_isGround = false;
	}
	if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS)
	{
		m_Position.x -= 100 * dt;
	}
	if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS)
	{
		for(int i = 0;;)
		{
			int rpos = (int)((m_Position.y + i) + m_Size.y / 2) * MapPitch / 4 + (int)((m_Position.x + 1) + m_Size.x / 2);
			printf("%d \n", (int)((m_Position.y)));
			D3DXCOLOR rcolor = m_MapColor[rpos];
			if (rcolor.r == 1.f && rcolor.g == 0 && rcolor.b == 1.f)
			{
				i += 1;
			}
			else
			{
				m_Position.y -= i * dt;
				i = 0;
				break;
			}
		}
		m_Position.x += 100 * dt;
	}
	if (INPUT->GetKey(VK_UP) == KeyState::PRESS)
	{
		m_Position.y -= 100 * dt;
	}
	if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS)
	{
		m_Position.y += 100 * dt;
	}
}

void Player::Render()
{
	m_Player->Render();
}
