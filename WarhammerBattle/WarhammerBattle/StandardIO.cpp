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

int StandardIO::GetResponse(std::string message, std::string validResponses)
{
	std::cout << message << std::endl;
	return 1;
}

void StandardIO::ShowMessage(std::string message)
{
	std::cout << message << std::endl;
}
