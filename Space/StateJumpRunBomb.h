#pragma once
class StateJumpRunBomb : public PlayerState
{
public:
	StateJumpRunBomb();
	~StateJumpRunBomb();

	bool m_isJump;
	bool m_isFalled;
	int Dire;

	float m_Timer;

	Vec2 m_PrevPos;

	void Init(Player* player);
	void Update(Player* player);
};

