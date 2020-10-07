#include "stdafx.h"
#include"ArabianState.h"
#include "ArabianStateThrow.h"
#include"Arabian.h"

ArabianStateThrow::ArabianStateThrow()
{
}

ArabianStateThrow::~ArabianStateThrow()
{
}

void ArabianStateThrow::Init(Arabian* arabian)
{
	if (arabian->m_Dire == LEFT)
		arabian->ChangeImage(L"Painting/Enemy/Arabian/Left/Throw.bmp", 0, 19);
	else if (arabian->m_Dire == RIGHT)
		arabian->ChangeImage(L"Painting/Enemy/Arabian/Right/Throw.bmp", 0, 19);
}

void ArabianStateThrow::Update(Arabian* arabian)
{
}
