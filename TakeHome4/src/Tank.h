#ifndef _TANK_H
#define _TANK_H
#include <iostream>
#include"Valve.h"
#include"Observer.h"
#include"Subject.h"
using namespace std;
/**
 * @class Tank
 * @brief Represents a tank that stores fuel and has a valve to control the flow of fuel.
 * @details The Tank class is a concrete implementation of the Observer interface.
 * It has a capacity, fuel quantity, and a valve that can be used to control the flow of fuel.
 * The class also has a flag that is used to generate unique IDs for each instance of the class.
 */
class Tank : public Observer
{
public:
	//Constructor
	Tank(double _capacity);

	Valve* getValve();
	void incrementFlag();
	void setFuelQuantity(double);
	void setValveStatus(bool); //broken icin.
	void setStatus(bool);
	bool getValveStatus();
	bool IsBroken();
	double getCapacity();
	double getFuelQuantity();
	int getTankID();
private:
	Tank();

	bool broken;
	double fuel_quantity;
	//ID i�in flag. Her obje icin ayr� degil. Sinifin flagi.
	static int flag;
	int TankId;
	//cannot call ctor in class.
	Valve tankValve = Valve(flag);
	const double capacity;
};
// All fuel tanks� valves are closed as default. If a fuel tank�s valve is open, that tank can�t be 
//removed.
//There is no max tank count(Unlimited) (Tip: Use list instead of array.)
#endif // !_TANK_H