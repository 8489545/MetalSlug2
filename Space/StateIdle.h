#pragma once
class StateIdle : public PlayerState
{
public:
	StateIdle();
	~StateIdle();

	void Init(Player* player, std::wstring weapon = L"");
	void SetState(Player* player,State state);
	void Update(Player* player);
};

