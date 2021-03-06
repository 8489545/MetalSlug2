#include"stdafx.h"
#include "Camera.h"
Camera::Camera()
{
	Init();
}

Camera::~Camera()
{
}

void Camera::Init()
{
	m_Rotation = 0;
	m_Position = Vec2(0, 0);
	m_Scale = Vec2(1.f, 1.f);
	Follow(nullptr);
	m_MaxMapSize = Vec2(0, 0);
	m_MinMapSize = Vec2(0, 0);
}

void Camera::Translate()
{

}

void Camera::Follow(Object* obj)
{
	if (obj != nullptr)
	{
		m_Position.x = obj->m_Position.x - App::GetInst()->m_Width / 2;
		if (m_Position.y > m_MinMapSize.y && m_Position.y < m_MaxMapSize.y - App::GetInst()->m_Height)
			m_Position.y = obj->m_Position.y - App::GetInst()->m_Height / 2;
	}
}

void Camera::Update(float deltaTime, float time)
{
	Translate();

	if (INPUT->GetKey('D') == KeyState::PRESS && m_Position.x < m_MaxMapSize.x - App::GetInst()->m_Width)
	{
		m_Position.x += 1000 * dt;
	}
	if (INPUT->GetKey('A') == KeyState::PRESS && m_Position.x > m_MinMapSize.x)
	{
		m_Position.x -= 1000 * dt;
	}
	if (INPUT->GetKey('W') == KeyState::PRESS && m_Position.y < m_MaxMapSize.y - App::GetInst()->m_Height)
	{
		m_Position.y -= 500 * dt;
	}
	if (INPUT->GetKey('S') == KeyState::PRESS && m_Position.y > m_MinMapSize.y)
	{
		m_Position.y += 500 * dt;
	}

	if (m_Rotation >= 360)
		m_Rotation = 0;
}

void Camera::Render()
{
	D3DXMatrixRotationZ(&mRot, D3DXToRadian(m_Rotation));
	D3DXMatrixTranslation(&mTrans, -m_Position.x, -m_Position.y, 1.f);
	D3DXMatrixScaling(&mScale, m_Scale.x, m_Scale.y, 1.f);

	// ī�޶� 
	//mScale* mRot* mTrans
	mWorld = mScale * mRot * mTrans;
}
