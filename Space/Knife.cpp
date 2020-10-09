#include"stdafx.h"
#include "Knife.h"

Knife::Knife(Vec2 Pos,int Dire,float power, float angle)
{
	m_Knife = Sprite::Create(L"Painting/Enemy/Arabian/k.png");
	m_Knife->SetParent(this);

	m_Position = Pos;
	m_StartPos = Pos;

	m_Power = power;
	m_Angle = angle;

	m_Dire = Dire;
}

Knife::~Knife()
{
}

void Knife::Update(float delatTime, float Time)
{
	if (m_Dire == RIGHT)
	{
		m_Position.x = (m_Power * cos(D3DXToRadian(-60))) * m_Time + m_StartPos.x;
		m_Position.y = (m_Power * sin(D3DXToRadian(-60))) * m_Time + 0.15f / 2 * m_Time * m_Time + m_StartPos.y;
	}
	else if (m_Dire == LEFT)
	{
		m_Position.x = (-m_Power * cos(D3DXToRadian(60)) * m_Time) + m_StartPos.x;
		m_Position.y = (-m_Power * sin(D3DXToRadian(60)) * m_Time + 0.15f / 2 * m_Time * m_Time) + m_StartPos.y;
	}
	m_Time++;

	D3DXCOLOR color;
	int pos = (int)(m_Position.y) * Game::GetInst()->GetCollisionMapRect().Pitch / 4 + (int)(m_Position.x);
	if (m_Position.y > 0)
		color = Game::GetInst()->GetMapColor(pos);

	if ((color.r == 1.f && color.g == 0 && color.b == 1.f))
	{
		m_Destroy = true;
	}

	m_Knife->Rotate(D3DXToRadian(360));
}

void Knife::Render()
{
	m_Knife->Render();
}

void Knife::OnCollision(Object* other)
{
}
