#include "stdafx.h"
#include "GameException.h"


CGameException::CGameException(char const* const _Message):std::exception(_Message)
{
}


CGameException::~CGameException()
{
}
