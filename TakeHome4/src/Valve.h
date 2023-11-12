/**
 * @file Valve.h
 * @brief The header file of the Valve class.
 * @details This file contains the Valve class and its functions.
 * @note This code is an assignment of Object Oriented Programming Lesson, TakeHome4 on 2023 Fall Semester.
*/

#ifndef VALVE_H
#define VALVE_H
#include"Observer.h"
#include<iostream>
using namespace std;

// Single Responsibility Principle.
//! Valve sinifinin yalnizca tek bir amaci vardir. O da durumunu(status) belirlemektir.
class Valve : public Observer
{
private:
	bool status;
	int ID;
public:
	Valve(int);
	bool getStatus();
	void setStatus(bool);
	void Update(string) override;
};
#endif VALVE_H