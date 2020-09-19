#pragma once
class StateJumpShot : public PlayerState
{
public:
	StateJumpShot();
	~StateJumpShot();


	bool m_isJump;
	bool m_isFalled;
	int Dire;

	bool m_isShot;
	float m_Timer;

	Vec2 m_PrevPos;

	void Init(Player* player);
	void Update(Player* player);
};

