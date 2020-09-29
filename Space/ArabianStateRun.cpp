#include "stdafx.h"
#include"ArabianState.h"
#include "ArabianStateRun.h"
#include"Arabian.h"
#include"ArabianStateIdle.h"

ArabianStateRun::ArabianStateRun()
{
}

ArabianStateRun::~ArabianStateRun()
{
}

void ArabianStateRun::Init(Arabian* arabian)
{
	if(arabian->m_Dire == LEFT)
		arabian->ChangeImage(L"Painting/Enemy/Arabian/Left/Run.bmp", 0, 12);
	else if(arabian->m_Dire == RIGHT)
		arabian->ChangeImage(L"Painting/Enemy/Arabian/Right/Run.bmp", 0, 12);

	Dire = arabian->m_Dire;
}

void ArabianStateRun::Update(Arabian* arabian)
{
	if (Dire != arabian->m_Dire)
		Init(arabian);

	for (auto& iter : ObjMgr->m_Objects)
	{
		RECT rc;
		if (iter->m_Tag == "Player")
		{
			if (IntersectRect(&rc, &iter->m_Collision, &arabian->m_Sight->m_Collision))
			{
				if (iter->m_Position.x > (arabian->m_Sight->m_Collision.left + arabian->m_Sight->m_Collision.right) / 2)
				{
					arabian->Move(LEFT);
				}
				else if (iter->m_Position.x < (arabian->m_Sight->m_Collision.left + arabian->m_Sight->m_Collision.right) / 2)
				{
					arabian->Move(RIGHT);
				}
			}
			else
			{
				arabian->m_State = m_ArabianStateIdle;
				arabian->m_State->Init(arabian);
			}
		}
	}
}
