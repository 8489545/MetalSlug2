#pragma once
class StateDownMove : public PlayerState
{
public:
	StateDownMove();
	~StateDownMove();

	int Dire;

	void Init(Player* player);
	void Update(Player* player);
};

