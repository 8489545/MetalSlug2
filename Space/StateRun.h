#pragma once
class StateRun : public PlayerState
{
public:
	StateRun();
	~StateRun();

	void Init(Player* player);
	void SetState(Player* player, State state);
	void Update(Player* player);
};

