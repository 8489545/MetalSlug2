#include "stdafx.h"
#include"Arabian.h"
#include "ArabianState.h"
#include"ArabianStateIdle.h"
#include"ArabianStateRun.h"
#include"ArabianStatePrepare.h"
#include"ArabianStateAttack.h"
#include"ArabianStateThrow.h"

ArabianStateIdle* ArabianState::m_ArabianStateIdle = new ArabianStateIdle();
ArabianStateRun* ArabianState::m_ArabianStateRun = new ArabianStateRun();
ArabianStatePrepare* ArabianState::m_ArabianStatePrepare = new ArabianStatePrepare();
ArabianStateAttack* ArabianState::m_ArabianStateAttack = new ArabianStateAttack();
ArabianStateThrow* ArabianState::m_ArabianStateThrow = new ArabianStateThrow();

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
