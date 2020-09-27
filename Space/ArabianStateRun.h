#pragma once
class ArabianStateRun : public ArabianState
{
public:
	ArabianStateRun();
	~ArabianStateRun();

	void Init(Arabian* arabian);
	void Update(Arabian* arabian);
};

