#include "StandardIO.h"


StandardIO::StandardIO()
{
}

StandardIO::StandardIO(StandardIO& rightSide)
{

}


StandardIO::~StandardIO()
{
}

StandardIO* StandardIO::Create()
{
	return new StandardIO();
}

StandardIO* StandardIO::Clone()
{
	return new StandardIO(*this);
}

int StandardIO::GetUserInput(std::string message, std::string validResponses)
{
	std::cout << message << std::endl;
	return 1;
}

void StandardIO::ShowMessage(std::string message)
{
	std::cout << message << std::endl;
}
