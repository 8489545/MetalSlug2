#pragma once
class ArabianStateIdle : public ArabianState
{
public:
	ArabianStateIdle();
	~ArabianStateIdle();

	void Init(Arabian* arabian);
	void Update(Arabian* arabian);
};

