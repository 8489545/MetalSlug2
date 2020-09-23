#include "stdafx.h"
#include "Bomb.h"

Bomb::Bomb(Vec2 Pos,int Dire)
{
	m_BombBox = Sprite::Create(L"Painting/Player/Att/BombBox.png");
	m_BombBox->SetParent(this);

	m_Bomb = new Animation();
	m_Bomb->Init(0.01f, true, BigImage);
	m_Bomb->AddContinueFrame(L"Painting/Player/Att/Bomb.bmp",1,32,COLORKEY_PINK);
	m_Bomb->SetPosition(m_Position.x - m_Bomb->m_Size.x + m_Size.x, m_Position.y - (m_Bomb->m_Size.y * m_Bomb->m_Scale.y - m_Size.y));
	m_Bomb->Render();

	m_BombBox->m_Visible = false;

	m_Position = Pos;
	m_Pos = Pos;

	m_Dire = Dire;

	m_Time = 0.f;
	m_GR = 0.15f;
	m_Power = 7.f;
}

Bomb::~Bomb()
{
}

void Bomb::Update(float deltaTime, float Time)
{
	if (!Game::GetInst()->m_DebugMode)
		m_BombBox->m_Visible = false;
	else
		m_BombBox->m_Visible = true;


	if (m_Dire == RIGHT)
	{
		m_Position.x = (m_Power * cos(D3DXToRadian(-60))) * m_Time + m_Pos.x;
		m_Position.y = (m_Power * sin(D3DXToRadian(-60))) * m_Time + m_GR / 2 * m_Time * m_Time + m_Pos.y;
	}
	else if (m_Dire == LEFT)
	{
		m_Position.x = (-m_Power * cos(D3DXToRadian(60)) * m_Time) + m_Pos.x;
		m_Position.y = (-m_Power * sin(D3DXToRadian(60)) * m_Time + m_GR / 2 * m_Time * m_Time) + m_Pos.y;
	}
	m_Time++;

	D3DXCOLOR color;
	int pos = (int)(m_Position.y) * Game::GetInst()->GetCollisionMapRect().Pitch / 4 + (int)(m_Position.x);
	if (m_Position.y > 0)
		color = Game::GetInst()->GetMapColor(pos);

	if ((color.r == 1.f && color.g == 0 && color.b == 1.f))
	{
		ObjMgr->AddObject(new EffectMgr(L"Painting/Effect/player_bomb.bmp", 1, 23, 0.05f,BigImage, Vec2(m_Position.x,m_Position.y - 200)), "Effect");
		m_Destroy = true; 
	}

	m_Bomb->SetPosition(m_Position.x - m_Bomb->m_Size.x + m_Size.x, m_Position.y - (m_Bomb->m_Size.y * m_Bomb->m_Scale.y - m_Size.y));
	m_Bomb->Update(deltaTime, Time);
}

void Bomb::Render()
{
	m_Bomb->Render();
	m_BombBox->Render();
}

void Bomb::OnCollision(Object* other)
{
}
