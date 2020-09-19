#pragma once
class StateShot : public PlayerState
{
public:
	StateShot();
	~StateShot();

	bool m_isShot;

	float m_Timer;

	void Init(Player* player);
	void Update(Player* player);
};

