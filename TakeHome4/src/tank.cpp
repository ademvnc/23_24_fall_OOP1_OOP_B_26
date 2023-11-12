#include "Tank.h"
int Tank::flag = 0;

Tank::Tank() : capacity(NULL)
{

}
/**
 * @brief Constructs a Tank object with the given fuel capacity.
 * 
 * @param _capacity The fuel capacity of the tank.
 */
Tank::Tank(double _capacity) : capacity(_capacity)
{
	this->TankId = flag;
	incrementFlag();
	broken = false;
	fuel_quantity = 0;
}
Valve* Tank::getValve()
{
	return &tankValve;
}
void Tank::incrementFlag()
{
	flag++;
}
void Tank::setValveStatus(bool state)
{
	this->tankValve.setStatus(state);
}
void Tank::setStatus(bool state)
{
	broken = state;
}
void Tank::setFuelQuantity(double quanty)
{
	fuel_quantity = quanty;
}
bool Tank::getValveStatus()
{
	return this->tankValve.getStatus();
}
bool Tank::IsBroken()
{
	return broken;
}
double Tank::getCapacity()
{
	return this->capacity;
}
double Tank::getFuelQuantity()
{
	return fuel_quantity;
}
int Tank::getTankID()
{
	return this->TankId;
}