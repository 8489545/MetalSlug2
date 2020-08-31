#pragma once
class StateRun : public PlayerState
{
public:
	StateRun();
	~StateRun();

	void Init(Player* player, std::wstring weapon = L"");
	void SetState(Player* player, State state);
	void Update(Player* player);
};

