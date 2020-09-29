#pragma once
class ArabianStateRun : public ArabianState
{
public:
	ArabianStateRun();
	~ArabianStateRun();

	int Dire;

	void Init(Arabian* arabian);
	void Update(Arabian* arabian);
};

