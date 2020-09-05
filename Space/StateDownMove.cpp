#include "stdafx.h"
#include "StateDownMove.h"
#include"StateIdle.h"
#include"StateDownShot.h"
#include"StateDown.h"

StateDownMove::StateDownMove()
{
}

StateDownMove::~StateDownMove()
{
}

void StateDownMove::Init(Player* player)
{
	if (player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"down_move.bmp", 0, 7, L"Painting/Player/Right/Top/" + player->m_Weapon + L"down_move.bmp", 0, 7);
	else if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"down_move.bmp", 0, 7, L"Painting/Player/Left/Top/" + player->m_Weapon + L"down_move.bmp", 0, 7);

	Dire = player->m_Dire;
}

void StateDownMove::Update(Player* player)
{
	if (Dire != player->m_Dire)
		Init(player);
	player->Move();
	if (INPUT->GetKey(VK_RIGHT) == KeyState::UP || INPUT->GetKey(VK_LEFT) == KeyState::UP || INPUT->GetKey(VK_DOWN) == KeyState::UP)
	{
		player->m_State = m_Down;
		player->m_State->Init(player);
	}
	if (INPUT->GetKey('S') == KeyState::DOWN)
	{
		player->m_State = m_DownShot;
		player->m_State->Init(player);
	}
}
