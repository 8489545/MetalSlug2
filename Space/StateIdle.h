#pragma once
class StateIdle : public PlayerState
{
public:
	StateIdle();
	~StateIdle();

	void SetState(Player& player, State state);
	void Update(Player& player);
};

