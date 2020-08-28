#pragma once
class Player : public Object
{
	Sprite* m_Player;
public:
	Player(Vec2 Pos);
	~Player();

	DWORD* m_MapColor;

	int MapWidth;
	INT MapPitch;

	bool m_isGround;

	void Update(float deltaTime,float Time);
	void Render();
};

