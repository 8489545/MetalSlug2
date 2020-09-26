#pragma once

class StateIdle;
class StateRun;
class StateJump;
class StateJumpRun;
class StateAppear;
class StateUnder;
class StateUp;
class StateShot;
class StateUpShot;
class StateUnderShot;
class StateDown;
class StateDownMove;
class StateDownShot;
class StateJumpShot;
class StateJumpRunShot;
class StateBomb;
class StateJumpBomb;

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
	static StateShot* m_Shot;
	static StateUpShot* m_UpShot;
	static StateUnderShot* m_UnderShot;
	static StateDown* m_Down;
	static StateDownMove* m_DownMove;
	static StateDownShot* m_DownShot;
	static StateJumpShot* m_JumpShot;
	static StateJumpRunShot* m_JumpRunShot;
	static StateBomb* m_Bomb;
	static StateJumpBomb* m_JumpBomb;
};