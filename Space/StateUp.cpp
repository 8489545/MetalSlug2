#include "stdafx.h"
#include "StateUp.h"
#include"StateIdle.h"
#include"StateUpShot.h"

StateUp::StateUp()
{
}

StateUp::~StateUp()
{
}

void StateUp::Init(Player* player)
{
	if (player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"Up.bmp", 0, 4, L"Painting/Player/Right/Bottom/Stand.bmp", 0, 1);
	if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"Up.bmp", 0, 4, L"Painting/Player/Left/Bottom/Stand.bmp", 0, 1);
}

void StateUp::Update(Player* player)
{
	if (INPUT->GetKey(VK_UP) == KeyState::UP)
	{
		player->m_State = m_Idle;
		player->m_State->Init(player);
	}
	if (INPUT->GetKey('S') == KeyState::DOWN)
	{
		player->m_State = m_UpShot;
		player->m_State->Init(player);
	}
} 
