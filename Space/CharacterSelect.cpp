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

		m_PanelUp[i] = true;
		m_PanelSpeed[i] = 0.f;

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
	m_Title->m_Layer = 2;

	m_Marco = new Animation();
	m_Marco->Init(0, false, MultipleImage);
	m_Marco->AddContinueFrame(L"Painting/Select/Marco", 1, 3, COLORKEY_WHITE);

	m_Eri = new Animation();
	m_Eri->Init(0, false, MultipleImage);
	m_Eri->AddContinueFrame(L"Painting/Select/Eri", 1, 3, COLORKEY_WHITE);

	m_Tarma = new Animation();
	m_Tarma->Init(0, false, MultipleImage);
	m_Tarma->AddContinueFrame(L"Painting/Select/Tarma", 1, 3, COLORKEY_WHITE);

	m_Fio = new Animation();
	m_Fio->Init(0, false, MultipleImage);
	m_Fio->AddContinueFrame(L"Painting/Select/Fio", 1, 3, COLORKEY_WHITE);

	m_Marco->SetPosition(46, 202);
	m_Eri->SetPosition(226, 202);
	m_Tarma->SetPosition(406, 202);
	m_Fio->SetPosition(585, 202);

	m_Marco->m_Layer = -1;
	m_Eri->m_Layer = -1;
	m_Tarma->m_Layer = -1;
	m_Fio->m_Layer = -1;

	m_Marco->m_CurrentFrame = 0;
	m_Eri->m_CurrentFrame = 0;
	m_Tarma->m_CurrentFrame = 0;
	m_Fio->m_CurrentFrame = 0;


	ObjMgr->AddObject(m_Marco, "Character");
	ObjMgr->AddObject(m_Eri, "Character");
	ObjMgr->AddObject(m_Tarma, "Character");
	ObjMgr->AddObject(m_Fio, "Character");

	ObjMgr->AddObject(m_BG, "Character");
	ObjMgr->AddObject(m_Title, "Character");

	m_NowSelectCharacter = Marco;
	m_Decision = false;
}

void CharacterSelect::Release()
{
}

void CharacterSelect::PanelUp(int PanelNum)
{
	if (m_Panels[PanelNum]->m_Position.y >= -m_Panels[PanelNum]->m_Size.y / 2 + 60)
	{
		m_PanelSpeed[PanelNum] += 10.f * dt;
		m_Panels[PanelNum]->m_Position.y -= m_PanelSpeed[PanelNum];
	}
}

void CharacterSelect::PanelDown(int PanelNum)
{
	if (m_Panels[PanelNum]->m_Position.y < 192)
	{
		m_PanelSpeed[PanelNum] += 10.f * dt;
		m_Panels[PanelNum]->m_Position.y += m_PanelSpeed[PanelNum];
	}
}

void CharacterSelect::SetCharacter()
{
	if (m_NowSelectCharacter == Marco)
	{
		m_Marco->m_CurrentFrame = 1;
		m_Eri->m_CurrentFrame = 0;
		m_Tarma->m_CurrentFrame = 0;
		m_Fio->m_CurrentFrame = 0;
	}
	else if (m_NowSelectCharacter == Eri)
	{
		m_Marco->m_CurrentFrame = 0;
		m_Eri->m_CurrentFrame = 1;
		m_Tarma->m_CurrentFrame = 0;
		m_Fio->m_CurrentFrame = 0;
	}
	else if (m_NowSelectCharacter == Tarma)
	{
		m_Marco->m_CurrentFrame = 0;
		m_Eri->m_CurrentFrame = 0;
		m_Tarma->m_CurrentFrame = 1;
		m_Fio->m_CurrentFrame = 0;
	}
	else if (m_NowSelectCharacter == Fio)
	{
		m_Marco->m_CurrentFrame = 0;
		m_Eri->m_CurrentFrame = 0;
		m_Tarma->m_CurrentFrame = 0;
		m_Fio->m_CurrentFrame = 1;
	}
}

void CharacterSelect::DecisionCharacter()
{
	if (INPUT->GetKey(VK_RETURN) == KeyState::DOWN)
	{
		m_Decision = true;
		if (m_NowSelectCharacter == Marco)
		{
			m_Marco->m_CurrentFrame = 2;
		}
		else if (m_NowSelectCharacter == Eri)
		{
			m_Eri->m_CurrentFrame = 2;
		}
		else if (m_NowSelectCharacter == Tarma)
		{
			m_Tarma->m_CurrentFrame = 2;
		}
		else if (m_NowSelectCharacter == Fio)
		{
			m_Fio->m_CurrentFrame = 2;
		}
	}
}

void CharacterSelect::Update(float deltaTime, float Time)
{ 
	if (!m_Decision)
	{
		PanelUp(0);
		PanelUp(1);
		PanelUp(2);
		PanelUp(3);
		SetCharacter();
		DecisionCharacter();
		if (INPUT->GetKey(VK_RIGHT) == KeyState::DOWN)
		{
			if (m_NowSelectCharacter < MaxCharacter)
				m_NowSelectCharacter++;
			else
				m_NowSelectCharacter = 0;

		}
		else if (INPUT->GetKey(VK_LEFT) == KeyState::DOWN)
		{
			if (m_NowSelectCharacter > 0)
				m_NowSelectCharacter--;
			else
				m_NowSelectCharacter = MaxCharacter;

		}
	}
	if(m_Decision)
	{
		if (m_NowSelectCharacter == Marco)
		{
			PanelDown(1);
			PanelDown(2);
			PanelDown(3);
		}
		else if (m_NowSelectCharacter == Eri)
		{
			PanelDown(0);
			PanelDown(2);
			PanelDown(3);
		}
		else if (m_NowSelectCharacter == Tarma)
		{
			PanelDown(0);
			PanelDown(1);
			PanelDown(3);
		}
		else if (m_NowSelectCharacter == Fio)
		{
			PanelDown(0);
			PanelDown(1);
			PanelDown(2);
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
	m_Title->SetPosition(78, 19);
}

void CharacterSelect::Render()
{
}
