/**
 * @file engine.h
 * @brief The Engine class represents the engine of a vehicle. It is responsible for storing fuel, consuming fuel, and generating power to move the vehicle.
 * @details The Engine class is a singleton class that implements the Observer interface. It has an internal tank to store fuel and can be connected to external tanks.
 * The engine can be started or stopped, and its throttle can be adjusted to control the power output. The engine also has health and heat properties that affect its performance.
 * @authors ademvnc beytullahorhan
 * @date 12/11/2023
 * @version 1.0
 * @note This code is an assignment of Object Oriented Programming Lab 1, TakeHome4 on 2023 Fall Semester.
 */
#ifndef _ENGINE_H
#define _ENGINE_H
#include"Observer.h"
#include"ExternalTank.h"
#include"InternalTank.h"
#include<iostream>
#include<vector>

//!The engine has its internal tank to store fuel.
//!Singleton Design Pattern uygulanacak. Uyguland�
using namespace std;

class Engine : public Observer
{
public:

	//!Destructor
	~Engine();

	static Engine* getInstance();
	InternalTank* getITank();
	void Update(string) override;
	void setStatus(bool);
	void setQuantityOfInternalTank(double);
	void setFuelPerSecond(double);
	void EngineHeatUp(int);
	void EngineCoolDown();
	void setHealth(int);
	void setHeat(int);
	void setFullThrottle(bool);
	bool getStatus();
	bool isFullThrottle();
	double getFuelPerSecond();
	double getQuantityOfInternalTank();
	int getHealth();
	int getHeat(); //! test i�in
	vector<Tank*>ConnectedTanks;
private:

	//!private constructor for singleton.
	Engine();

	static Engine* instance; //!Singleton instance

	//!The engine has its internal tank to store fuel. Internal tank capacity will be 55.0
	//!Cannot call ctor in class definition.
	InternalTank iTank = InternalTank(55.0);

	bool fullThrottle;
	int heat; //! idle->90, stopped->20, full throttle-unlimited.
	int health;
	double fuelPerSecond;
	bool status; //!status->working.
};
#endif //! !_ENGINE_H