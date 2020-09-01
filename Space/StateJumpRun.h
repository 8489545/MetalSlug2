#pragma once
class StateJumpRun : public PlayerState
{
public:
	StateJumpRun();
	~StateJumpRun();

	bool m_isJump;
	bool m_isFalled;

	Vec2 m_PrevPos;

	void Init(Player* player);
	void Update(Player* player);
};

