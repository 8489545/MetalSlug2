#include "stdafx.h"
#include "StateAppear.h"
#include"StateIdle.h"

StateAppear::StateAppear()
{
}

StateAppear::~StateAppear()
{
}

void StateAppear::Init(Player* player)
{
	player->ChangeImage(L"Painting/Player/Appear.bmp", 1, 7);
}

void StateAppear::Update(Player* player)
{
	if (player->m_Body->m_CurrentFrame == 6 && player->m_isGround)
	{
		SafeDelete(player->m_Body);
		player->m_State = m_Idle;
		player->m_State->Init(player);
	}
}
