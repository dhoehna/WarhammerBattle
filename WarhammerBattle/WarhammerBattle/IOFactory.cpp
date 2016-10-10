#include "IOFactory.h"

IOFactory* Factory = NULL; // Used for the singleton pattern


/*-----------------------------------------------------------------------------
 @name Instance
 @description gets the singleton instance of this factory
 @retyrn a pointer to the IO factory
*/
IOFactory* IOFactory::Instance()
{
	if (Factory == NULL)
	{
		Factory = new IOFactory();
	}
	return Factory;
}


/*-----------------------------------------------------------------------------
 @name DeleteFactory
 @description removes the factory from memory.
*/
void IOFactory::DeleteFactory()
{
	delete Factory;
	Factory = NULL;
}


/*-----------------------------------------------------------------------------
 @name constructor
 @description makes a new IOFactory and sets up the factory with IO objects.
*/
IOFactory::IOFactory()
{
	IOHolder["Standard"] = new StandardIO();
}

/*-----------------------------------------------------------------------------
 @name destructor
 @description detroys the factory
*/
IOFactory::~IOFactory()
{
	//intentionally left blank.
}


/*-----------------------------------------------------------------------------
 @name Get
 @Description gets a new instance of the IIO based onthe genera passed in.
 @Param ioMethod the method of IO
 @return a pointer to the new IIO class.
*/
IIO* IOFactory::Get(std::string ioMethod)
{
	IIO* ToReturn = IOHolder[ioMethod];
	if (ToReturn != NULL)
	{
		return ToReturn->Create();
	}
	else
		return NULL;
}

