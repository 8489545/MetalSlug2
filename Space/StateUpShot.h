#pragma once
class StateUpShot : public PlayerState
{
public:
	StateUpShot();
	~StateUpShot();

	void Init(Player* player);
	void Update(Player* player);
};

