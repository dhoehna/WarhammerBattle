#include "IO.h"

/*-----------------------------------------------------------------------------
 @name basic constructor
 @description sets up the IO class.
*/
IO::IO(IIO* IOMechanizm) : IOMechanizm(IOMechanizm)
{
	/* left blank intentionally*/
}


/*-----------------------------------------------------------------------------
 @name Copy constructor
 @desciption make a 
*/
IO::IO(IO& rightSide)
{
	
}


IO::~IO()
{
	/* nothing to do here*/
}

IO* IO::Create(IIO* IOMechanizm)
{
	return new IO(IOMechanizm);
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
