#include "stdafx.h"
#include "StateIdle.h"

StateIdle::StateIdle()
{
}

StateIdle::~StateIdle()
{
}

void StateIdle::Init(Player* player, std::wstring weapon)
{
	if(player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + weapon + L"Stand.bmp", 0, 4, L"Painting/Player/Right/Bottom/Stand.bmp", 0, 1);
	else if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + weapon + L"Stand.bmp", 0, 4, L"Painting/Player/Left/Bottom/Stand.bmp", 0, 1);
}

void StateIdle::SetState(Player* player,State state)
{
}

void StateIdle::Update(Player* player)
{
	if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS || INPUT->GetKey(VK_LEFT) == KeyState::PRESS)
	{
		player->m_State = PlayerState::m_Run;
		player->m_State->Init(player);
	}
}