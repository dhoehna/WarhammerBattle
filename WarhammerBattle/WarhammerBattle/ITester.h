#ifndef ITESTER_H
#define ITESTER_H

class ITester
{
	virtual void RunAllTests() = 0;
	virtual void Initilize() = 0;
	virtual void CleanUp() = 0;
};

#endif