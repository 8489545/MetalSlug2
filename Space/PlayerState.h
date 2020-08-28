#pragma once
class PlayerState
{
public:
	PlayerState();
	virtual ~PlayerState();

	
	virtual void SetState(Player& player, State state);
	virtual void Update(Player& player);
};

