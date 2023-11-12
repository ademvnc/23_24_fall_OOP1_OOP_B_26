/**
 * @file SimulationData.cpp
 * @brief This file contains the implementation of the SimulationData.h file.
 * @details This file contains the implementations of the functions in the SimulationData.h file.
 * @authors ademvnc beytullahorhan
 * @date 12/11/2023
 * @version 1.0
 * @note This code is an assignment of Object Oriented Programming Lab 1, TakeHome4 on 2023 Fall Semester.
 * 
 */

#include "SimulationData.h"

void SimulationData::registerObserver(Observer* observer)
{
	observers.push_back(observer);
}

/**
 * @brief Removes an observer from the list of observers.
 * 
 * @param observer Pointer to the observer to be removed.
 */
void SimulationData::removeObserver(Observer* observer)
{
	auto iterator = std::find(observers.begin(), observers.end(), observer);
	if (iterator != observers.end()) { // observer found
		observers.erase(iterator); // remove the observer
	}
}

void SimulationData::notifyObservers()
{
	for (Observer* observer : observers) { // notify all observers
		observer->Update(message);
	}
}

void SimulationData::setMessage(std::string message_)
{
	this->message = message_;
	notifyObservers();
}
