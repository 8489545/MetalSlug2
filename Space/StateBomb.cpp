#include "stdafx.h"
#include "StateBomb.h"
#include"Bomb.h"
#include"StateIdle.h"

StateBomb::StateBomb()
{
}

StateBomb::~StateBomb()
{
}

void StateBomb::Init(Player* player)
{
	if (player->m_Dire == RIGHT)
		player->ChangeImage(L"Painting/Player/Right/Top/" + player->m_Weapon + L"bomb.bmp", 0, 6, L"Painting/Player/Right/Bottom/stand.bmp", 0, 1);
	if (player->m_Dire == LEFT)
		player->ChangeImage(L"Painting/Player/Left/Top/" + player->m_Weapon + L"bomb.bmp", 0, 6, L"Painting/Player/Left/Bottom/stand.bmp", 0, 1);

	ObjMgr->AddObject(new Bomb(player->m_Position,player->m_Dire), "Bomb");
}

void StateBomb::Update(Player* player)
{
	if (player->m_Top->m_CurrentFrame == 6)
	{
		player->m_State = m_Idle;
		player->m_State->Init(player);
	}
}
