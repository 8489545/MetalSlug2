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

	m_isHit = false;
}

void ArabianStateAttack::Update(Arabian* arabian)
{
	if (arabian->m_Body->m_CurrentFrame == 2 && !m_isHit)
	{
		for (auto& iter : ObjMgr->m_Objects)
		{
			if (iter->m_Tag == "Player")
			{
				RECT rc;
				if (IntersectRect(&rc, &iter->m_Collision, &arabian->m_Collision))
				{
					m_isHit = true;
					Game::GetInst()->PlayerDeath();
					Game::GetInst()->CreatePlayer();
				}
			}
		}
	}
	if (arabian->m_Body->m_CurrentFrame == 8)
	{
		arabian->m_State = m_ArabianStateIdle;
		arabian->m_State->Init(arabian);
	}
}
