#include "stdafx.h"
#include "StateDown.h"
#include"StateIdle.h"
#include"StateDownMove.h"

StateDown::StateDown()
{
}

StateDown::~StateDown()
{
}

void StateDown::Init(Player* player)
{
	if (player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"Down.bmp", 0, 4, L"Painting/Player/Right/Top/" + player->m_Weapon + L"Down.bmp", 0, 4);
	else if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"Down.bmp", 0, 4, L"Painting/Player/Left/Top/" + player->m_Weapon + L"Down.bmp", 0, 4);
}

void StateDown::Update(Player* player)
{
	if (INPUT->GetKey(VK_DOWN) == KeyState::UP)
	{
		player->m_State = m_Idle;
		player->m_State->Init(player);
	}
	if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS || INPUT->GetKey(VK_LEFT) == KeyState::PRESS)
	{
		player->m_State = m_DownMove;
		player->m_State->Init(player);
	}
}
