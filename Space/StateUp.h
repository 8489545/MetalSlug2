#pragma once
class StateUp : public PlayerState
{
public:
	StateUp();
	~StateUp();

	void Init(Player* player);
	void Update(Player* player);
};

