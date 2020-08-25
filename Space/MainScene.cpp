#include "stdafx.h"
#include "MainScene.h"
#include"Player.h"

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}

void MainScene::Init()
{
	m_Neogeo = Sprite::Create(L"Painting/Logo/Neogeo.bmp");
	m_Neogeo->SetPosition(0, 0);

	m_Logo = Sprite::Create(L"Painting/Logo/Logo.bmp");
	m_Logo->SetPosition(0, 0);
	m_Logo->m_Visible = false;

	m_Start = new Animation();
	m_Start->Init(0, false);
	m_Start->AddContinueFrame(L"Painting/Button/Start.bmp", 1, 2,COLORKEY_WHITE);

	m_Edit = new Animation();
	m_Edit->Init(0, false);
	m_Edit->AddContinueFrame(L"Painting/Button/Edit.bmp", 1, 2, COLORKEY_WHITE);

	m_Exit = new Animation();
	m_Exit->Init(0, false);
	m_Exit->AddContinueFrame(L"Painting/Button/Exit.bmp", 1, 2, COLORKEY_WHITE);


	m_Neogeo->A = 0;

	m_DestroyNeogeo = false;
	m_Start->m_Visible = false;
	m_Edit->m_Visible = false;
	m_Exit->m_Visible = false;

	ObjMgr->AddObject(m_Neogeo, "UI");
	//ObjMgr->AddObject(m_Logo, "UI");
	ObjMgr->AddObject(m_Start, "UI");
	ObjMgr->AddObject(m_Edit, "UI");
	ObjMgr->AddObject(m_Exit, "UI");

	m_Start->SetPosition(100, 500);
	m_Edit->SetPosition(350, 500);
	m_Exit->SetPosition(600, 500);

	m_StartLine = new LineMgr();
	m_StartLine->Init(1, true);
	m_StartLine->SetColor(D3DXCOLOR(255, 255, 255, 255));
}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{
	if (m_Neogeo->A < 255)
	{
		m_Neogeo->A += 1;
	}	

	if (INPUT->GetButtonDown() || m_Neogeo->A == 255)
	{
		m_DestroyNeogeo = true;
		m_Neogeo->A = 255;
		m_Neogeo->SetDestroy(true);
		INPUT->ButtonDown(false);
	}

	if (m_DestroyNeogeo == true)
	{
		m_Logo->m_Visible = true;
		m_Start->m_Visible = true;
		m_Edit->m_Visible = true;
		m_Exit->m_Visible = true;


		if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Start))
		{
			m_Start->m_CurrentFrame = 2;
		}
		else
		{
			m_Start->m_CurrentFrame = 1;
		}
	}

	m_Start->SetVertex();
	m_Edit->SetVertex();
	m_Exit->SetVertex();
}

void MainScene::Render()
{
	m_StartLine->DrawLine(m_Start->m_Vertex, 2);
}
