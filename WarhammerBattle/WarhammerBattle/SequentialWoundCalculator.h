#pragma once
#include "IWoundCalculator.h"
class SequentialWoundCalculator :
	public IWoundCalculator
{
public:
	SequentialWoundCalculator();
	~SequentialWoundCalculator();
};

