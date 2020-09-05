#pragma once
class StateUnderShot : public PlayerState
{
public:
	StateUnderShot();
	~StateUnderShot();

	bool m_isJump;
	bool m_isFalled;
	int Dire;

	Vec2 m_PrevPos;

	void Init(Player* player);
	void Update(Player* player);
};

