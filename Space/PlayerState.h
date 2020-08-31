#pragma once
enum class State
{
	IDLE,
	SHOT,
	JUMP,
	RUN,
	BOMB,
	DOWN,
	UP,
	DEATH,
	NONE
};
class StateIdle;
class StateRun;
class PlayerState
{
public:
	PlayerState();
	virtual ~PlayerState();


	virtual void Init(Player* player,std::wstring weapon = L"");
	virtual void SetState(Player* player,State state);
	virtual void Update(Player* player);

	static StateIdle* m_Idle;
	static StateRun* m_Run;
};

