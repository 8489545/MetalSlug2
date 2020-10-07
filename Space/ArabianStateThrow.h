#pragma once
class ArabianStateThrow : public ArabianState
{
public:
	ArabianStateThrow();
	~ArabianStateThrow();

	void Init(Arabian* arabian);
	void Update(Arabian* arabian);
};

