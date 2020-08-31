#pragma once

class StateIdle;
class StateRun;
class StateJump;

class PlayerState
{
public:
	PlayerState();
	virtual ~PlayerState();


	virtual void Init(Player* player);
	virtual void SetState(Player* player);
	virtual void Update(Player* player);

	static StateIdle* m_Idle;
	static StateRun* m_Run;
	static StateJump* m_Jump;
};