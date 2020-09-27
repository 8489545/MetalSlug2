#include "stdafx.h"
#include"ArabianState.h"
#include "ArabianStateIdle.h"
#include"Arabian.h"

ArabianStateIdle::ArabianStateIdle()
{
}

ArabianStateIdle::~ArabianStateIdle()
{
}

void ArabianStateIdle::Init(Arabian* arabian)
{
	arabian->ChangeImage(L"Painting/Enemy/Arabian/Idle.bmp", 0, 12);
}

void ArabianStateIdle::Update(Arabian* arabian)
{
}
