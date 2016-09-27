/*
	WHAT IS THIS?
	This is the interface for all IO interaction with the simulator.

	WHAT DOES THIS HAVE?
	A method to get user response and a method to just show a message.
	*/

#include <string>
class IIO
{
public:
	/*-------------------------------------------------------------------------
	@name GetUserResponse
	@Description show the user the passed in message and waits for a response.
	@Param message the message to show to the user
	@param validResponses the responses the program will accept.
	*/
	virtual int GetResponse(std::string message, std::string validResponses) = 0;

	/*-------------------------------------------------------------------------
	@name ShowMessage
	@Description sends a message
	@param message the message to show the user
	*/
	virtual void ShowMessage(std::string message) = 0;
};