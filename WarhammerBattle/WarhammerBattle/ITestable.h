#ifndef ITESTABLE_H
#define ITESTABLE_H
class ITestable
{
public:
	virtual bool operator==(ITestable& rightSide) = 0;
};
#endif
