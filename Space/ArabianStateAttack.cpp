#include "stdafx.h"
#include"ArabianState.h"
#include "ArabianStateAttack.h"
#include"Arabian.h"
#include"ArabianStateIdle.h"

ArabianStateAttack::ArabianStateAttack()
{
}

ArabianStateAttack::~ArabianStateAttack()
{
}

void ArabianStateAttack::Init(Arabian* arabian)
{
	if (arabian->m_Dire == LEFT)
		arabian->ChangeImage(L"Painting/Enemy/Arabian/Left/Attack.bmp", 0, 8);
	else if (arabian->m_Dire == RIGHT)
		arabian->ChangeImage(L"Painting/Enemy/Arabian/Right/Attack.bmp", 0, 8);
}

void ArabianStateAttack::Update(Arabian* arabian)
{
	if (arabian->m_Body->m_CurrentFrame == 8)
	{
		arabian->m_State = m_ArabianStateIdle;
		arabian->m_State->Init(arabian);
	}
}
