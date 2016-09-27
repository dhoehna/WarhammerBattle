#include "IO.h"

/*-----------------------------------------------------------------------------
 @name basic constructor
 @description sets up the IO class.
*/
IO::IO(IIO* IOMechanizm) : IOMechanizm(IOMechanizm);
{
	/* left blank intentionally*/
}


/*-----------------------------------------------------------------------------
 @name Copy constructor
 @desciption make a 
*/
IO::IO(IO& rightSide)
{
	this->IOMechanizm = new IIO(rightSide.IOMechanizm);
}


IO::~IO()
{
	/* nothing to do here*/
}

int IO::GetUserResponse(std::string message, char* validResponses)
{
	std::cout << message << std::endl;
	return 1;
}


void IO::ShowMessage(std::string message)
{
	std::cout << message << std::endl;
}
