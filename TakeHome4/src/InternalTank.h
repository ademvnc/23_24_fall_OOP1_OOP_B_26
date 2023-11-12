
/**
 * @file InternalTank.h
 * @class InternalTank
 * @brief A class representing an internal tank that inherits from the Tank class.
 * @authors ademvnc beytullahorhan
 * @date 12/11/2023
 * @version 1.0
 * @note This code is an assignment of Object Oriented Programming Lab 1, TakeHome4 on 2023 Fall Semester.
 * 
 */

#ifndef INTERNALTANK_H
#define INTERNALTANK_H
#include"Tank.h"
//!The engine has its internal tank to store fuel. Internal tank capacity will be 55.0
/**
 * @brief A class representing an internal tank that inherits from the Tank class.
 */
class InternalTank : public Tank
{
public:
    /**
     * @brief Constructs an InternalTank object with the specified capacity.
     * 
     * @param capacity The capacity of the internal tank.
     */
    InternalTank(double capacity);

    /**
     * @brief Updates the internal tank with the specified message.
     * 
     * @param message_ The message to update the internal tank with.
     */
    void Update(string message_);
};
#endif // !INTERNALTANK_H
