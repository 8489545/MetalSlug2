#include "stdafx.h"
#include"ArabianState.h"
#include "ArabianStateThrow.h"
#include"Arabian.h"
#include"ArabianStateIdle.h"

ArabianStateThrow::ArabianStateThrow()
{
}

ArabianStateThrow::~ArabianStateThrow()
{
}

void ArabianStateThrow::Init(Arabian* arabian)
{
	for (auto& iter : ObjMgr->m_Objects)
	{
		if (iter->m_Tag == "Player")
		{
			if (iter->m_Position.x + iter->m_Size.x / 2 > (arabian->m_Sight->m_Collision.left + arabian->m_Sight->m_Collision.right) / 2)
			{
				arabian->m_Dire = RIGHT;
			}
			else if (iter->m_Position.x + iter->m_Size.x / 2 < (arabian->m_Sight->m_Collision.left + arabian->m_Sight->m_Collision.right) / 2)
			{
				arabian->m_Dire = LEFT;
			}
		}
	}
	if (arabian->m_Dire == LEFT)
		arabian->ChangeImage(L"Painting/Enemy/Arabian/Left/Throw.bmp", 0, 19);
	else if (arabian->m_Dire == RIGHT)
		arabian->ChangeImage(L"Painting/Enemy/Arabian/Right/Throw.bmp", 0, 19);

	arabian->m_ThrowCoolDown = 3.f;
}

void ArabianStateThrow::Update(Arabian* arabian)
{
	if (arabian->m_Body->m_CurrentFrame == 18)
	{
		arabian->m_State = m_ArabianStateIdle;
		arabian->m_State->Init(arabian);
	}
}
