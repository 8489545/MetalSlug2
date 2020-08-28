#pragma once
class Texture;
class Game : public Singleton<Game>
{
private:
	D3DLOCKED_RECT m_CollisionMapRect;
	DWORD* m_MapColor;

public:
	Game();
	~Game();

	void Init();
	void Release();
	void CollisionMapInit(Sprite* cMap);

	DWORD GetMapColor(int pos) { return m_MapColor[pos]; }
	D3DLOCKED_RECT GetCollisionMapRect() { return m_CollisionMapRect; }

};

