#include"InternalTank.h"

/**
 * @file InternalTank.cpp
 * @brief Constructs a new InternalTank object with the given capacity.
 * @details This constructor calls the Tank constructor with the given capacity.
 * @param capacity The maximum fuel capacity of the internal tank.
 * @authors ademvnc beytullah orhan
 * @date 12/11/2023
 * @version 1.0
 * @note This code is an assignment of Object Oriented Programming Lab 1, TakeHome4 on 2023 Fall Semester.
 * 
 */
InternalTank::InternalTank(double capacity) : Tank(capacity)
{
	this->setValveStatus(1);
	this->setFuelQuantity(0);
}

void InternalTank::Update(string message_)
{
	cout << "Internal Tank " << getTankID() << ": " << message_ << endl;
}
