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

class Player;
class StateIdle;
class PlayerState
{
public:
	PlayerState();
	virtual ~PlayerState();

	
	virtual void Init(Player* player);
	virtual void SetState(Player* player,State state);
	virtual void Update();

	static StateIdle* m_Idle;
};

