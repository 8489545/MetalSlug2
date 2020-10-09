#include "stdafx.h"
#include "Arabian.h"
#include"ArabianState.h"

Arabian::Arabian(Vec2 Pos)
{
	m_Arabian = Sprite::Create(L"Painting/Enemy/Arabian/Body.png");
	m_Arabian->SetParent(this);

	m_Sight = Sprite::Create(L"Painting/Enemy/Arabian/Sight.png");

	m_Position = Pos;

	m_isGround = false;
	m_vY = 0.f;

	m_Dire = RIGHT;

	m_State->SetIdle(this);
	m_Body->m_Position = Pos;

	m_Speed = 150.f;
	m_ThrowCoolDown = 0.f;
}

Arabian::~Arabian()
{
}

void Arabian::ChangeImage(std::wstring body, int first, int last)
{
	if (m_Body)
		ObjMgr->RemoveObject(m_Body);

	m_Body = new Animation();
	m_Body->Init(0.1f, true, BigImage);
	m_Body->AddContinueFrame(body, first, last, COLORKEY_PINK);
	m_Body->Render();
	m_Body->SetScale(2, 2);

	SetImagePos();
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

void Arabian::SetImagePos()
{
	m_Body->SetPosition(m_Position.x - m_Body->m_Size.x + m_Size.x / 2, m_Position.y - m_Body->m_Size.y + m_Size.y / 2);
	m_Sight->m_Position.x = m_Position.x - m_Sight->m_Size.x / 2 + 30;
	m_Sight->m_Position.y = m_Position.y - m_Sight->m_Size.y / 2;
}

void Arabian::Move(int Dire)
{     
	if (Dire == RIGHT)
	{
		m_Dire = LEFT;
		int lpos = (int)((m_Position.y) + m_Size.y) * Game::GetInst()->GetCollisionMapRect().Pitch / 4 + (int)((m_Position.x + 1) + m_Size.x / 2);
		D3DXCOLOR lcolor = Game::GetInst()->GetMapColor(lpos);

		m_Position.x -= m_Speed * dt;
		if (!(lcolor.r == 0.f && lcolor.g == 0 && lcolor.b == 0.f))
		{
			m_Position.y -= m_Speed / 2 * dt;
		}
	}
	else if (Dire == LEFT)
	{
		m_Dire = RIGHT;
		int rpos = (int)((m_Position.y) + m_Size.y) * Game::GetInst()->GetCollisionMapRect().Pitch / 4 + (int)((m_Position.x + 1) + m_Size.x / 2);
		D3DXCOLOR rcolor = Game::GetInst()->GetMapColor(rpos);

		m_Position.x += m_Speed * dt;
		if (!(rcolor.r == 0.f && rcolor.g == 0 && rcolor.b == 0.f))
		{
			m_Position.y -= m_Speed / 2 * dt;
		}
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

	if (m_ThrowCoolDown > 0.f)
		m_ThrowCoolDown -= dt;

	Gravity();
	SetImagePos();

	m_State->Update(this);

	if(m_Body)
		m_Body->Update(deltaTime, Time);
}

void Arabian::Render()
{
	if(m_Body)
		m_Body->Render();
	m_Sight->Render();
	m_Arabian->Render();

	SetRect(&m_Collision, m_Position.x, m_Position.y,
		m_Position.x + m_Size.x, m_Position.y + m_Size.y);
}

void Arabian::OnCollision(Object* other)
{
}
