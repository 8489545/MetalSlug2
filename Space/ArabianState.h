#pragma once
class Arabian;
class ArabianState
{
public:
	ArabianState();
	virtual ~ArabianState();

	
	void SetState(Arabian* arabian);

	virtual void Init(Arabian* arabian) = 0;
	virtual void Update(Arabian* arabian) = 0;
};

