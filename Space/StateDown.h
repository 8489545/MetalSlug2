#pragma once
class StateDown : public PlayerState
{
public:
	StateDown();
	~StateDown();

	void Init(Player* player);
	void Update(Player* player);
};

