#include "Valve.h"

Valve::Valve(int id)
{
	this->ID = id;
	this->status = false;
}
bool Valve::getStatus()
{
	return status;
}
void Valve::setStatus(bool state)
{
	this->status = state;
}

/**
 * @brief Updates the valve with a given message.
 * 
 * @param message_ The message to update the valve with.
 */
void Valve::Update(string message_)
{
	cout << "Valve " << ID << ": " << message_ << endl;
}
