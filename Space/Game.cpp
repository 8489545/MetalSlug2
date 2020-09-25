#include "stdafx.h"
#include "Game.h"
#include"Texture.h"
#include"UI.h"

Game::Game()
{
	ZeroMemory(&m_CollisionMapRect, sizeof(m_CollisionMapRect));
}

Game::~Game()
{
}

void Game::Init()
{
	m_isCreateUI = false;
}

void Game::Release()
{
}

void Game::CollisionMapInit(Sprite* cMap)
{
	cMap->GetSpriteTexture()->GetTexture()->LockRect(0, &m_CollisionMapRect, 0, 0);
	m_MapColor = (DWORD*)m_CollisionMapRect.pBits;
	cMap->GetSpriteTexture()->GetTexture()->UnlockRect(0);
}

void Game::CreateUI()
{
	if (!m_isCreateUI)
	{
		UI::GetInst()->Init();
		m_isCreateUI = true;
	}
}

void Game::Update()
{
	if (m_isCreateUI)
		UI::GetInst()->Update();
}

void Game::Render()
{
	if (m_isCreateUI)
		UI::GetInst()->Render();
}
