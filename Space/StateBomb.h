#pragma once
class StateBomb : public PlayerState
{
public:
	StateBomb();
	~StateBomb();


	void Init(Player* player);
	void Update(Player* player);
};

