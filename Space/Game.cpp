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
	m_DebugMode = false;
	m_isCreatePlayer = false;
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

void Game::CreatePlayer()
{
	ObjMgr->AddObject(new Player(Vec2(0, 0)), "Player");
	m_isCreatePlayer = true;
}

void Game::PlayerDeath()
{
	m_isCreatePlayer = false;
	ObjMgr->DeleteObject("Player");
	ObjMgr->DeleteObject("pBullet");
}

void Game::Update()
{
	if (INPUT->GetKey('V') == KeyState::DOWN)
	{
		if (m_DebugMode)
		{
			m_DebugMode = false;
		}
		else if (!m_DebugMode)
		{
			m_DebugMode = true;
		}
	}

	if (m_isCreateUI)
		UI::GetInst()->Update();
}

void Game::Render()
{
	if (m_isCreateUI)
		UI::GetInst()->Render();
}
