/**
 * @file Observer.h
 * @brief This file contains the declaration of the Observer class.
 * @details This file contains the declaration of the Observer class.
 * @authors ademvnc beytullahorhan
 * @date 12/11/2023
 * @version 1.0
 * @note This code is an assignment of Object Oriented Programming Lab 1, TakeHome4 on 2023 Fall Semester.
 */


#pragma once
#include<string>

using namespace std;

//! Dependency Inversion Principle.
//! There is no direct dependency of the low-level classes on the abstract observer interface that we have defined.
//! By eliminating the dependencies of high-level classes on low-level classes, we can now perform operations through the abstract layer.

/**
 * @brief The Observer class is an abstract class that defines the interface for objects that should be notified of changes in a subject.
 */
class Observer
{
public:
	virtual void Update(string) = 0;
};