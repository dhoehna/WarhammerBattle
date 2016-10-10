#pragma once
#include "TestBase.h"
#include "StandardIO.h"
class StandardIOTests :
	public TestBase
{
public:
	StandardIOTests();
	virtual ~StandardIOTests();

	void RunAllTests();

private:
	void RunTest(std::string methodName);

	void TestCreate();
};

