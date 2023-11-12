/**
 * @file ExternalTank.cpp
 * @brief This file contains the implementation of the ExternalTank.h file.
 * @details This file contains the implementations of the functions in the ExternalTank.h file.
 * @authors ademvnc beytullahorhan
 * @date 12/11/2023
 * @version 1.0
 * @note This code is an assignment of Object Oriented Programming Lab 1, TakeHome4 on 2023 Fall Semester.
 * 
 * 
 */

#include "ExternalTank.h"

ExternalTank::ExternalTank(double capacity) : Tank(capacity)
{
}

void ExternalTank::Update(string message_)
{
	cout << "Tank " << getTankID() << ": " << message_ << endl;
}

/**
 * @brief Class representing an external fuel tank.
 * 
 */
ExternalTank ExternalTank::operator+(ExternalTank& eTank)
{
	double quantityF = this->getFuelQuantity();
	double quantityS = eTank.getFuelQuantity();

	ExternalTank newTank(quantityF + quantityS);
	return newTank;
}
