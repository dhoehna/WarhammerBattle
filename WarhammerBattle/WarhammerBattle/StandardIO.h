/*
	WHAT IS THIS?
	This class handled input and out put with cout and cin.
*/

#pragma once
#include "IIO.h"
#include <string>
#include <iostream>
class StandardIO :
	public IIO
{
public:
	StandardIO();
	StandardIO(StandardIO& rightSide);
	virtual ~StandardIO();

	StandardIO* Create();
	StandardIO* Clone();

	virtual int GetUserInput(std::string message, std::string validInputs);
	virtual void ShowMessage(std::string message);
};

