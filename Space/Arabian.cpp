#include "stdafx.h"
#include "Arabian.h"

Arabian::Arabian(Vec2 Pos)
{
	m_Arabian = Sprite::Create(L"Painting/Enemy/Arabian/Body.png");
	m_Arabian->SetParent(this);

	m_Body = new Animation();
	m_Body->Init(0.06f, true, BigImage);
	m_Body->AddContinueFrame(L"Painting/Enemy/Arabian/Idle.bmp",0,12);
	m_Body->Render();
	m_Body->SetScale(2, 2);

	m_Sight = Sprite::Create(L"Painting/Enemy/Arabian/Sight.png");

	m_Position = Pos;
	m_Body->m_Position = Pos;

	m_isGround = false;
	m_vY = 0.f;
}

Arabian::~Arabian()
{
}

void Arabian::Gravity()
{
	D3DXCOLOR undercolor;

	int underpos = ((int)(m_Position.y + m_Size.y) + 1) * Game::GetInst()->GetCollisionMapRect().Pitch / 4 + (int)(m_Position.x + m_Size.x / 2);
	if (m_Position.y > 0)
		undercolor = Game::GetInst()->GetMapColor(underpos);

	if ((undercolor.r == 1.f && undercolor.g == 0 && undercolor.b == 1.f))
	{
		m_isGround = true;
		m_vY = 0.f;
	}
	else
	{
		m_isGround = false;
	}

	if (!m_isGround)
	{
		m_vY += 9.8f * dt;
		m_Position.y += m_vY;
	}
}

void Arabian::Update(float deltaTime, float Time)
{
	if (!Game::GetInst()->m_DebugMode)
	{
		m_Arabian->m_Visible = false;
		m_Sight->m_Visible = false;
	}
	else
	{
		m_Arabian->m_Visible = true;
		m_Sight->m_Visible = true;
	}

	Gravity();

	m_Body->SetPosition(m_Position.x - m_Size.x,m_Position.y - m_Size.y / 2);
	m_Sight->SetPosition(m_Position.x - m_Sight->m_Size.x / 2 + m_Arabian->m_Size.x / 2, m_Position.y - m_Sight->m_Size.y / 2);

	m_Body->Update(deltaTime, Time);
}

void Arabian::Render()
{
	m_Arabian->m_Rect = m_Body->m_Rect;
	m_Collision = m_Arabian->m_Rect;
	m_Body->Render();
	m_Sight->Render();
	m_Arabian->Render();
}

void Arabian::OnCollision(Object* other)
{
}
