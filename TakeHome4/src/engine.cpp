/**
 * @file engine.cpp
 * @brief This file contains the implementation of the engine.h file.
 * @details This file contains the implementations of the functions in the engine.h file.
 * @author ademvnc beytullahorhan
 * @date 12/11/2023
 * @version 1.0
 * @note This code is an assignment of Object Oriented Programming Lab 1, TakeHome4 on 2023 Fall Semester.
 * 
*/


#include "Engine.h"

//! Private constructor.
Engine::Engine()
{
    this->status = 0;
    this->heat = 20;
    this->health = 100;
    this->fullThrottle = 0;
    this->fuelPerSecond = 5.5;
}

//! Sets the status of the engine.
void Engine::setStatus(bool status) { this->status = status; }

//! Sets the quantity of fuel in the internal tank.
void Engine::setQuantityOfInternalTank(double fuel)
{
    iTank.setFuelQuantity(fuel);
}

//! Sets the fuel consumption rate of the engine.
void Engine::setFuelPerSecond(double value)
{
    this->fuelPerSecond = value;
}

//! Increases the heat of the engine.
void Engine::EngineHeatUp(int seconds)
{
    if (this->fullThrottle) //! full throttle açık.
    {
        if (this->heat < 90)
        {
            if (this->health > 0) this->health -= 1 * seconds;
        }
        this->heat += (seconds * 5);
    } //! motor açık değilken sorun çıkarabilir.!!!
    else //! idle mod.
    {
        if (this->heat < 90)
        {
            this->heat += seconds * 1;
        }
    }
    if (this->heat > 130)
    {
        if (this->health > 0) this->health -= 1;
    }
}

//! Decreases the heat of the engine.
void Engine::EngineCoolDown()
{
    if (this->heat > 20) //! 20'den yüksek
    {
        this->heat -= 1; //! düşür
    }
}

//! Sets the health of the engine.
void Engine::setHealth(int health)
{
    this->health = health;
}

//! Sets the heat of the engine.
void Engine::setHeat(int heat)
{
    this->heat = heat;
}

//! Sets the full throttle status of the engine.
void Engine::setFullThrottle(bool status)
{
    this->fullThrottle = status;
}

//! Returns the status of the engine.
bool Engine::getStatus() { return status; }

//! Returns whether the engine is at full throttle.
bool Engine::isFullThrottle()
{
    return this->fullThrottle;
}

//! Returns the fuel consumption rate of the engine.
double Engine::getFuelPerSecond()
{
    return this->fuelPerSecond;
}

//! Returns the quantity of fuel in the internal tank.
double Engine::getQuantityOfInternalTank()
{
    return iTank.getFuelQuantity();
}

//! Returns the health of the engine.
int Engine::getHealth()
{
    return this->health;
}

//! Returns the heat of the engine.
int Engine::getHeat()
{
    return this->heat;
}

//! Returns the instance of the engine.
Engine* Engine::getInstance()
{
    if (instance == NULL)
    {
        instance = new Engine;
    }
    return instance;
}

//! Destructor.
Engine::~Engine()
{
}

//! Returns a pointer to the internal tank.
InternalTank* Engine::getITank()
{
    return &iTank;
}

//! Updates the engine with a message.
void Engine::Update(string message_)
{
    cout << "Engine: " << message_ << endl;
}
