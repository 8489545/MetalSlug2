#include "stdafx.h"
#include"ArabianState.h"
#include "ArabianStateIdle.h"
#include"Arabian.h"
#include"ArabianStateRun.h"

ArabianStateIdle::ArabianStateIdle()
{
}

ArabianStateIdle::~ArabianStateIdle()
{
}

void ArabianStateIdle::Init(Arabian* arabian)
{
	if (arabian->m_Dire == LEFT)
		arabian->ChangeImage(L"Painting/Enemy/Arabian/Left/Idle.bmp", 0, 12);
	else if (arabian->m_Dire == RIGHT)
		arabian->ChangeImage(L"Painting/Enemy/Arabian/Right/Idle.bmp", 0, 12);
}

void ArabianStateIdle::Update(Arabian* arabian)
{
	for (auto& iter : ObjMgr->m_Objects)
	{
		RECT rc;
		if (iter->m_Tag == "Player")
		{
			if (IntersectRect(&rc,&iter->m_Collision,&arabian->m_Sight->m_Collision))
			{
				arabian->m_State =  m_ArabianStateRun;
				arabian->m_State->Init(arabian);
			}
		}
	}
}
