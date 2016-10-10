#pragma once
#include <string>
#include <iostream>
class TestBase
{
	virtual void RunAllTests() = 0;

	virtual void RunTest(std::string methodName) = 0;
};
