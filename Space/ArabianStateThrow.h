#pragma once
class ArabianStateThrow : public ArabianState
{
public:
	ArabianStateThrow();
	~ArabianStateThrow();

	bool m_isThrow;

	void Init(Arabian* arabian);
	void Update(Arabian* arabian);
};

