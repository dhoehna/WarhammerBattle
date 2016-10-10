/*
	WHAT IS THIS?
	This is a factory for making different kinds of IIO classes.

	WHAT IS AN IIO CLASS?  Well, you can look at the .h file.  But, basically
	AN iio CLASS IS Away to do input and output of the program.

	ANY ASSUMPTIONS?
	None that I can think of.
*/

#ifndef IOFactory_H
#define	IOFactory_H
#include <string>
#include <map>
#include "IIO.h"
#include "StandardIO.h"


class IOFactory
{
public:

	static IOFactory* Instance();

	/*----------------------------------------------------------------------------
	 @name DeleteFactory
	 @description removes the factory from existence
	*/
	void DeleteFactory();

	/*----------------------------------------------------------------------------
	 @name Get
	 @description gets the IIO class for IO
	 @param ioMethod the way you want to do the IO
	 @return a pointer to the IO class.
	*/
	IIO* Get(std::string ioMethod);

private:

	std::map<std::string, IIO*> IOHolder;

	/*----------------------------------------------------------------------------
	 @name Constructor
	 @description sets up the IO factory
	*/
	IOFactory();

	/*----------------------------------------------------------------------------
	 @name destructor
	 @description destroys the IO factory.  It was making too much smog.
	*/
	virtual ~IOFactory();

};

#endif	/* IOFactory_H */

