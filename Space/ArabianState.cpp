#include "stdafx.h"
#include"Arabian.h"
#include "ArabianState.h"
#include"ArabianStateIdle.h"

ArabianStateIdle* ArabianState::m_ArabianStateIdle = new ArabianStateIdle();

ArabianState::ArabianState()
{
}

ArabianState::~ArabianState()
{
}

void ArabianState::SetIdle(Arabian* arabian)
{
	arabian->m_State = m_ArabianStateIdle;
	arabian->m_State->Init(arabian);
}
