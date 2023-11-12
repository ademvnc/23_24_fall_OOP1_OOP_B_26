#ifndef EXTERNALTANK_H
#define EXTERNALTANK_H
#include "Tank.h"
using namespace std;
/**
 * @file ExternalTank.h
 * @class ExternalTank
 * @brief A class representing an external tank that inherits from Tank.
 * @details
 * This class represents an external tank that can be used to store liquids. It inherits from the Tank class.
 * It has a constructor that takes the capacity of the tank as a parameter, an Update method that takes a message as a parameter,
 * and an operator+ method that allows two external tanks to be added together.
 * @see Tank
 * @see InternalTank
 * @see Engine
 * @see Observer
 * @see Subject
 * @see ExternalTank
 * @authors ademvnc beytullahorhan
 * @date 12/11/2023
 * @version 1.0
 * @note This code is an assignment of Object Oriented Programming Lab 1, TakeHome4 on 2023 Fall Semester.
 */
class ExternalTank : public Tank
{
public:
	ExternalTank(double capacity);
	void Update(string message_);
	//!Objede modify yapilacagi icin const olmamali.
	ExternalTank operator+(ExternalTank& eTank);
};
#endif // !EXTERNALTANK_H