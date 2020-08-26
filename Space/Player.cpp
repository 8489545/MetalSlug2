#include "stdafx.h"
#include "Player.h"

Player::Player(Vec2 Pos)
{
	m_PlayerTop = new Animation();
	m_PlayerTop->Init(0.1f, true, BigImage);
	m_PlayerTop->AddContinueFrame(L"Painting/Player/Right/Top.bmp", 1, 11);

	m_PlayerBottom = new Animation();
	m_PlayerBottom->Init(0.1f, true, BigImage);
	m_PlayerBottom->AddContinueFrame(L"Painting/Player/Right/Bottom.bmp", 1, 11);

	m_PlayerTop->m_Position = Pos;

	m_PlayerDirection = RIGHT;

	m_State = State::IDLE;

}

Player::~Player()
{
}

void Player::SetPlayerAni()
{
	if (m_PlayerDirection == LEFT)
	{
		Dire = L"Left";
	}
	else if (m_PlayerDirection == RIGHT)
	{
		Dire = L"Right";
	}
}

void Player::Update(float deltaTime, float Time)
{
	SetPlayerAni();

	m_PlayerTop->Update(deltaTime,Time);
	m_PlayerBottom->Update(deltaTime, Time);
}

void Player::Render()
{
	m_PlayerTop->Render();
	m_PlayerBottom->Render();
}
