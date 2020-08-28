#include "stdafx.h"
#include "StateIdle.h"

StateIdle::StateIdle()
{
}

StateIdle::~StateIdle()
{
}

void StateIdle::Init(Player* player)
{
	player->ChangeImage(L"Painting/Player/Right/Top/Stand.bmp", 0, 4, L"Painting/Player/Right/Bottom/Stand.bmp", 0, 1);
}

void StateIdle::SetState(Player* player,State state)
{
}

void StateIdle::Update()
{
}