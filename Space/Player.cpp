#include "stdafx.h"
#include "Player.h"


Player::Player(Vec2 Pos)
{
	m_Top = nullptr;
	m_Bottom = nullptr;

	m_Player = Sprite::Create(L"Painting/Player.png");
	m_Player->SetParent(this);

	SetPosition(800 / 2, 600 / 2);

	m_isGround = false;
	m_WeightY = 0;
	m_vY = 0.f;
	m_Player->m_Visible = false;

	m_Speed = 300.f;

	m_Dire = RIGHT;

	m_State = new PlayerState();
	m_State->SetState(this, State::IDLE);
	m_Weapon = L"";
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

	Animation* Top;
	Animation* Bottom;

	Top = new Animation();
	Top->Init(0.1f, true, BigImage);
	Top->AddContinueFrame(top, topfirst, toplast, COLORKEY_PINK);
	Top->SetScale(2.f, 2.f);
	Top->SetPosition(-1000, -1000);

	Bottom = new Animation();
	Bottom->Init(0.1f, true, BigImage);
	Bottom->AddContinueFrame(bottom, bottomfirst, bottomlast, COLORKEY_PINK);
	Bottom->SetScale(2.f, 2.f);
	Bottom->SetPosition(-1000, -1000);

	if(Top)
		m_Top = Top;
	if(Bottom)
		m_Bottom = Bottom;
}

void Player::ChangeImage(std::wstring body, int first, int last)
{
	if (m_Body)
		ObjMgr->RemoveObject(m_Body);

	m_Body = new Animation();
	m_Body->Init(0.1f, true, BigImage);
	m_Body->AddContinueFrame(body, first, last, COLORKEY_PINK);
}

void Player::Update(float deltaTime, float Time)
{
	if (INPUT->GetKey('V') == KeyState::DOWN)
	{
		if (m_Player->m_Visible)
			m_Player->m_Visible = false;
		else
			m_Player->m_Visible = true;
	}
	if (!m_isGround)
	{
		m_vY += 9.8f * dt;
		m_Position.y += m_vY;
	}

	Move();

	SetImagePos();
	if (m_Top)
		m_Top->Update(deltaTime, Time);
	if (m_Bottom)
		m_Bottom->Update(deltaTime, Time);
	if (m_Body)
		m_Body->Update(deltaTime, Time);
	Camera::GetInst()->Follow(this);
	m_State->Update(this);
}

void Player::Render()
{

	if (m_Top)
		m_Top->Render();
	if (m_Bottom)
		m_Bottom->Render(); 
	if (m_Body)
		m_Body->Render();

	m_Player->Render();
}

void Player::SetImagePos()
{
	if (m_Top)
		m_Top->SetPosition(m_Position.x - m_Top->m_Size.x / 2 - m_Size.x, m_Position.y - m_Top->m_Size.y / 2);
	if (m_Bottom)
		m_Bottom->SetPosition(m_Position.x - m_Bottom->m_Size.x / 2 - m_Size.x, m_Position.y - m_Bottom->m_Size.y / 2);
	if (m_Body)
		m_Body->SetPosition(m_Position.x - m_Body->m_Size.x / 2 - m_Size.x, m_Position.y + m_Body->m_Size.y / 2 + m_Size.y);
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
	if (INPUT->GetKey(VK_LEFT) == KeyState::DOWN)
		m_Dire = LEFT;
	if (INPUT->GetKey(VK_RIGHT) == KeyState::DOWN)
		m_Dire = RIGHT;
	if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS)
	{
		int lpos = (int)((m_Position.y - m_WeightY - 1) + m_Size.y) * Game::GetInst()->GetCollisionMapRect().Pitch / 4 + (int)((m_Position.x - 1) + m_Size.x / 2);
		D3DXCOLOR lcolor = Game::GetInst()->GetMapColor(lpos);

		
		if ((lcolor.r == 0.f && lcolor.g == 0 && lcolor.b == 0.f))
		{
			m_Position.x -= m_Speed * dt;
			m_Position.y -= m_WeightY * m_Speed / 2 * dt;
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

		if ((rcolor.r == 0.f && rcolor.g == 0 && rcolor.b == 0.f))
		{
			m_Position.x += m_Speed * dt;
			m_Position.y -= m_WeightY * m_Speed / 2 * dt;
			m_WeightY = 0;
		}
		else
		{
			m_WeightY++;
		}
	}
}
