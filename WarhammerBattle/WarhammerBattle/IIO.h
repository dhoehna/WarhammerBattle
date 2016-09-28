/*
	WHAT IS THIS?
	This is the interface for all IO interaction with the simulator.

	WHAT DOES THIS HAVE?
	A method to get user response and a method to just show a message.

	This uses the Virtual Constructor idiom
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
	 @return the returned answer in the form of an int. 
	*/
	virtual int GetUserInput(std::string message, std::string validResponses) = 0;

	/*-------------------------------------------------------------------------
	@name ShowMessage
	@Description sends a message
	@param message the message to show the user
	*/
	virtual void ShowMessage(std::string message) = 0;

	/*-------------------------------------------------------------------------
	 @name destructor
	 @dexcription does nothing in this class.  Used for base classes.
	*/
	virtual ~IIO() {}

	/*-------------------------------------------------------------------------
		@name Create
		@decription used to create an instance of this class.
		@return a pointer to a new IIO class.
	*/
	virtual IIO* Create() = 0;

	/*-------------------------------------------------------------------------
	 @name clone
	 @description used to clone a derived class
	 @return a pointer to the new clone IIO class.
	*/
	virtual IIO* Clone() = 0;
};