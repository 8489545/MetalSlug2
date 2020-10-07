#include"stdafx.h"
#include"ArabianState.h"
#include "ArabianStatePrepare.h"
#include"Arabian.h"
#include"ArabianStateIdle.h"

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
		//arabian->m_State = m_ArabianStateIdle;
		//arabian->m_State->Init(arabian);
	}
}
