#include "stdafx.h"
#include "CharacterSelect.h"

CharacterSelect::CharacterSelect()
{
}

CharacterSelect::~CharacterSelect()
{
}

void CharacterSelect::Init()
{
	m_BG = Sprite::Create(L"Painting/Select/BG.bmp",COLORKEY_WHITE);
	m_BG->SetPosition(0, 0);

	for (int i = 0; i <= 3; i++)
	{
		m_Panels[i] = Sprite::Create(L"Painting/Select/Panel.bmp",COLORKEY_WHITE);
		ObjMgr->AddObject(m_Panels[i], "Character");
	}
	m_Panels[0]->SetPosition(46, 192);
	ObjMgr->AddObject(m_BG, "Character");
}

void CharacterSelect::Release()
{
}

void CharacterSelect::Update(float deltaTime, float Time)
{
}

void CharacterSelect::Render()
{
}
