#pragma once
class StateRun : public PlayerState
{
public:
	StateRun();
	~StateRun();

	void Init(Player* player);
	void Update(Player* player);
};

