#pragma once
class StateUnder : public PlayerState
{
public:
	StateUnder();
	~StateUnder();

	bool m_isJump;
	bool m_isFalled;
	int Dire;

	Vec2 m_PrevPos;

	void Init(Player* player);
	void Update(Player* player);
};

