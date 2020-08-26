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

		m_Player[i] = Sprite::Create(L"Painting/Select/" + std::to_wstring(i + 1) + L".png", COLORKEY_WHITE);
		m_Player[i]->m_Layer = 2;
		m_Player[i]->m_Visible = false;
		ObjMgr->AddObject(m_Player[i], "Character");
	}
	m_Panels[0]->SetPosition(46, 192);
	m_Panels[1]->SetPosition(226, 192);
	m_Panels[2]->SetPosition(406, 192);
	m_Panels[3]->SetPosition(585, 192);

	m_Player[0]->SetPosition(64, 107);
	m_Player[1]->SetPosition(230, 107);
	m_Player[2]->SetPosition(443, 107);
	m_Player[3]->SetPosition(610, 107);

	m_Title = Sprite::Create(L"Painting/Select/Title.bmp", COLORKEY_WHITE);
	m_Title->SetPosition(78, 19);
	m_Title->m_Layer = 3;
	

	ObjMgr->AddObject(m_BG, "Character");
	ObjMgr->AddObject(m_Title, "Character");

	m_NowSelectCharacter = Marco;
}

void CharacterSelect::Release()
{
}

void CharacterSelect::Update(float deltaTime, float Time)
{
	if (INPUT->GetKey(VK_RIGHT) == KeyState::DOWN)
	{
		if (m_NowSelectCharacter < MaxCharacter)
		{
			m_NowSelectCharacter++;
		}
		else
		{
			m_NowSelectCharacter = 0;
		}
	}
	else if (INPUT->GetKey(VK_LEFT) == KeyState::DOWN)
	{
		if (m_NowSelectCharacter > 0)
		{
			m_NowSelectCharacter--;
		}
		else
		{
			m_NowSelectCharacter = MaxCharacter;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (i == m_NowSelectCharacter)
		{
			m_Player[i]->m_Visible = true;
		}
		else
		{
			m_Player[i]->m_Visible = false;
		}
	}

}

void CharacterSelect::Render()
{
}
