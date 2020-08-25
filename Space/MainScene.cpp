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
	m_Ani = new Animation();
	m_Ani->Init(0.1f, true);
	m_Ani->AddContinueFrame(L"Painting/Camel/Run.bmp", 1, 11);
	m_Ani->SetPosition(800 / 2, 600 / 2);
}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{
	m_Ani->Update(deltaTime, time);
}

void MainScene::Render()
{
	m_Ani->Render();
}
