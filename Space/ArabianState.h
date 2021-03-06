#pragma once
class Arabian;

class ArabianStateIdle;
class ArabianStateRun;
class ArabianStatePrepare;
class ArabianStateAttack;
class ArabianStateThrow;
class ArabianStateDeath;

class ArabianState
{
public:
	ArabianState();
	virtual ~ArabianState();

	
	void SetIdle(Arabian* arabian);
	void Death(Arabian* arabian);

	virtual void Init(Arabian* arabian) = 0;
	virtual void Update(Arabian* arabian) = 0;

	static ArabianStateIdle* m_ArabianStateIdle;
	static ArabianStateRun* m_ArabianStateRun;
	static ArabianStatePrepare* m_ArabianStatePrepare;
	static ArabianStateAttack* m_ArabianStateAttack;
	static ArabianStateThrow* m_ArabianStateThrow;
	static ArabianStateDeath* m_ArabianStateDeath;
};

