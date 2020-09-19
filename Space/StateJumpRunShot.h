#pragma once
class StateJumpRunShot : public PlayerState
{
public:
	StateJumpRunShot();
	~StateJumpRunShot();

	bool m_isJump;
	bool m_isFalled;
	int Dire;

	bool m_isShot;
	float m_Timer;

	Vec2 m_PrevPos;

	void Init(Player* player);
	void Update(Player* player);
};

