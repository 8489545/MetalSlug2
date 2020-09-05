#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(std::wstring filename, Vec2 arrival,Vec2 pos,float speed)
{
	m_Bullet = Sprite::Create(filename, COLORKEY_PINK);
	m_Bullet->SetParent(this);

	m_Position = pos;
	m_Arrival = arrival - m_Position;
	m_Speed = speed;
	m_Timer = 0.f;
}

Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime, float Time)
{
	D3DXVec2Normalize(&Dire, &m_Arrival);
	m_Timer += dt;
	Translate(Dire.x * m_Speed * dt, Dire.y * m_Speed * dt);

	
	if (m_Timer >= 3.f)
		SetDestroy(true);
}

void Bullet::Render()
{
	m_Bullet->Render();
}
