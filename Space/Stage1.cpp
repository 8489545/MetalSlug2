#include "stdafx.h"
#include "Stage1.h"
#include "Player.h"

void Stage1::Init()
{
	m_Map = Sprite::Create(L"Painting/Map/Misson1.bmp");
	m_Map->SetPosition(0, 0);
	m_CMap = Sprite::Create(L"Painting/Map/CMap1.bmp",COLORKEY_WHITE);
	m_CMap->SetPosition(0, 0);

	ObjMgr->AddObject(m_CMap, "CMap");

	Camera::GetInst()->m_MinMapSize = Vec2(0, 0);
	Camera::GetInst()->m_MaxMapSize = Vec2(m_Map->m_Size.x, 0);

	Game::GetInst()->CollisionMapInit(m_CMap);

	ObjMgr->AddObject(new Player(Vec2(0,0)),"Player");
}

void Stage1::Release()
{
}

void Stage1::Update(float deltaTime, float Time)
{
	if (INPUT->GetKey('V') == KeyState::DOWN)
	{
		if (m_CMap->m_Visible)
			m_CMap->m_Visible = false;
		else
			m_CMap->m_Visible = true;
	}
}

void Stage1::Render()
{
	m_Map->Render();
}
