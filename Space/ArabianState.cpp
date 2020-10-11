#include "stdafx.h"
#include"Arabian.h"
#include "ArabianState.h"
#include"ArabianStateIdle.h"
#include"ArabianStateRun.h"
#include"ArabianStatePrepare.h"
#include"ArabianStateAttack.h"
#include"ArabianStateThrow.h"
#include"ArabianStateDeath.h"

ArabianStateIdle* ArabianState::m_ArabianStateIdle = new ArabianStateIdle();
ArabianStateRun* ArabianState::m_ArabianStateRun = new ArabianStateRun();
ArabianStatePrepare* ArabianState::m_ArabianStatePrepare = new ArabianStatePrepare();
ArabianStateAttack* ArabianState::m_ArabianStateAttack = new ArabianStateAttack();
ArabianStateThrow* ArabianState::m_ArabianStateThrow = new ArabianStateThrow();
ArabianStateDeath* ArabianState::m_ArabianStateDeath = new ArabianStateDeath();

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

void ArabianState::Death(Arabian* arabian)
{
	arabian->m_State = m_ArabianStateDeath;
	arabian->m_State->Init(arabian);
}
