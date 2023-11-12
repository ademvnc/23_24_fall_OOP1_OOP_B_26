#pragma once
#include<list>
#include<vector>
#include<iterator>
#include<string>
#include"Observer.h"
using namespace std;

//!Open-Closed Principle.
//! When we need to create a new Publisher (Subject) object, we should not make any changes to the Subject class itself
//! because we need to be closed for modification. Instead, we derive a new Publisher from the Subject class
//! and override the virtual methods in the new Publisher. This way, we remain open for extension, and
//! we don't need to make changes anywhere else (in the Subject class).

//!Liskov Substitution Principle.
//! Subclasses derived from the Subject class can use all the properties and methods of the superclass
//! in a way that performs the same function. Additionally, they can have their own unique features.
//! You can examine the SimulationData class for an example.

/**
 * @brief The Subject class is an abstract class that defines the interface for objects that can be observed.
 * 
 */
class Subject
{
public:
	virtual void registerObserver(Observer* observer) = 0;
	virtual void removeObserver(Observer* observer) = 0;
	virtual void notifyObservers() = 0;
};