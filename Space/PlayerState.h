#pragma once

class StateIdle;
class StateRun;
class StateJump;
class StateJumpRun;
class StateAppear;
class StateUnder;
class StateUp;

class PlayerState
{
public:
	PlayerState();
	virtual ~PlayerState();


	void SetState(Player* player);
	virtual void Init(Player* player);
	virtual void Update(Player* player);

	static StateIdle* m_Idle;
	static StateRun* m_Run;
	static StateJump* m_Jump;
	static StateJumpRun* m_JumpRun;
	static StateAppear* m_Appear;
	static StateUnder* m_Under;
	static StateUp* m_Up;
};