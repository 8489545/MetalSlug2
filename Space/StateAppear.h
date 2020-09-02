#pragma once
class StateAppear : public PlayerState
{
public:
	StateAppear();
	~StateAppear();

	void Init(Player* player);
	void Update(Player* player);
};

