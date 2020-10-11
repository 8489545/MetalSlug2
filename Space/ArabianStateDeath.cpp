#include"stdafx.h"
#include"ArabianState.h"
#include "ArabianStateDeath.h"
#include"Arabian.h"

ArabianStateDeath::ArabianStateDeath()
{
}

ArabianStateDeath::~ArabianStateDeath()
{
}

void ArabianStateDeath::Init(Arabian* arabian)
{
	if (arabian->m_Dire == LEFT)
		arabian->ChangeImage(L"Painting/Enemy/Arabian/Left/Death.bmp", 0, 11);
	else if (arabian->m_Dire == RIGHT)
		arabian->ChangeImage(L"Painting/Enemy/Arabian/Right/Death.bmp", 0, 11);
}

void ArabianStateDeath::Update(Arabian* arabian)
{
	if (arabian->m_Body->m_CurrentFrame == 11)
	{
		arabian->SetDestroy(true);
	}
}
