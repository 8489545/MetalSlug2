#pragma once
class StateShot : public PlayerState
{
public:
	StateShot();
	~StateShot();

	void Init(Player* player);
	void Update(Player* player);
};

