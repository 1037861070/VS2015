#include <exception>

#pragma once
class CGameException: public std::exception
{
public:
	CGameException(char const* const _Message);
	~CGameException();
};

