#pragma once
class ArabianStatePrepare : public ArabianState
{
public:
	ArabianStatePrepare();
	~ArabianStatePrepare();

	void Init(Arabian* arabian);
	void Update(Arabian* arabian);

	float m_Timer;
};

