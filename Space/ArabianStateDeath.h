#pragma once
class ArabianStateDeath : public ArabianState
{
public:
	ArabianStateDeath();
	~ArabianStateDeath();

	void Init(Arabian* arabian);
	void Update(Arabian* arabian);
};

