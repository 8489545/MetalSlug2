#pragma once
class ArabianStateAttack : public ArabianState
{
public:
	ArabianStateAttack();
	~ArabianStateAttack();

	void Init(Arabian* arabian);
	void Update(Arabian* arabian);
};

