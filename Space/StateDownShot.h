#pragma once
class StateDownShot : public PlayerState
{
public:
	StateDownShot();
	~StateDownShot();

	void Init(Player* player);
	void Update(Player* player);
};

