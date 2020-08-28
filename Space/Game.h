#pragma once
class Texture;
class Game : public Singleton<Game>
{
private:
	

	Sprite* m_CollisionMap;
	D3DLOCKED_RECT m_CollisionMapRect;
	DWORD* m_MapColor;

public:
	Game();
	~Game();

	void Init();
	void Release();
	void CollisionMapInit(Sprite* cMap);

	DWORD GetMapColor(int pos) { return m_MapColor[pos]; }
	//Sprite* GetCollisionMap() { return m_CollisionMap; }
	D3DLOCKED_RECT GetCollisionMapRect() { return m_CollisionMapRect; }

};

