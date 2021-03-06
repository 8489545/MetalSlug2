#include"stdafx.h"
#include"ArabianState.h"
#include "ArabianStatePrepare.h"
#include"Arabian.h"
#include"ArabianStateAttack.h"
#include"ArabianStateThrow.h"

ArabianStatePrepare::ArabianStatePrepare()
{
}

ArabianStatePrepare::~ArabianStatePrepare()
{
}

void ArabianStatePrepare::Init(Arabian* arabian)
{
	if (arabian->m_Dire == LEFT)
		arabian->ChangeImage(L"Painting/Enemy/Arabian/Left/Prepare.bmp", 0, 4);
	else if (arabian->m_Dire == RIGHT)
		arabian->ChangeImage(L"Painting/Enemy/Arabian/Right/Prepare.bmp", 0, 4);

	m_Timer = 0.f;
}

void ArabianStatePrepare::Update(Arabian* arabian)
{
	if (arabian->m_Body->m_CurrentFrame == 4)
	{
		if (arabian->m_ThrowCoolDown <= 0.f)
		{
			arabian->m_State = m_ArabianStateThrow;
			arabian->m_State->Init(arabian);
		}
		else
		{
			arabian->m_State = m_ArabianStateAttack;
			arabian->m_State->Init(arabian);
		}
	}
}
