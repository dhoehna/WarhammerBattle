/*
	WHAT IS THIS?
	Handles incput and output to std::cout and std::cin.
*/
#pragma once
#include <iostream>
#include "IIO.h"
class IO
{
private:
	IIO* IOMechanizm;

public:
	IO(IIO* IOMechanizm);
	IO(IO& rightSide);
	virtual ~IO();

	virtual IO* Create(IIO* IOMechanizm);
	virtual IO* Clone();

	int GetUserResponse(std::string message, char* validResponces);
	void ShowMessage(std::string message);
};

