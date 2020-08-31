#pragma once
class StateIdle : public PlayerState
{
public:
	StateIdle();
	~StateIdle();

	void Init(Player* player);
	void SetState(Player* player);
	void Update(Player* player);
};

