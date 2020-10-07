#pragma once
class ArabianStateAttack : public ArabianState
{
public:
	ArabianStateAttack();
	~ArabianStateAttack();

	bool m_isHit;

	void Init(Arabian* arabian);
	void Update(Arabian* arabian);
};

