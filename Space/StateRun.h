#pragma once
class StateRun : public PlayerState
{
public:
	StateRun();
	~StateRun();

	int Dire;
	void Init(Player* player);
	void Update(Player* player);
};

