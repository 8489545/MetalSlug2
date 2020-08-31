#pragma once
class StateJump : public PlayerState
{
public:
	StateJump();
	~StateJump();

	bool m_isJump;
	bool m_isFalled;

	Vec2 m_PrevPos;

	void Init(Player* player);
	void SetState(Player* player);
	void Update(Player* player);
};

