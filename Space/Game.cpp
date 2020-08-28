#include "stdafx.h"
#include "Game.h"
#include"Texture.h"

Game::Game()
{
	ZeroMemory(&m_CollisionMapRect, sizeof(m_CollisionMapRect));
}

Game::~Game()
{
}

void Game::Init()
{
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
