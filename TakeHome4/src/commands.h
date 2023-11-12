/**
 * @file commands.h
 * @brief This header file will contain all required definitions and basic utilities functions for the commands.cpp file.
 * @author ademvnc beytullahorhan
 * @date 12/11/2023
 * @version 1.0
 * @note This code is an assignment of Object Oriented Programming Lab 1, TakeHome4 on 2023 Fall Semester.       
 * 
*/

#ifndef _COMMANDS_H
#define _COMMANDS_H
#include<string>
#include"Engine.h"
#include"Tank.h"//iostream var
#include<fstream>
#include<iterator>
#include<vector>
using namespace std;

class Commands
{
public:
	Commands() {}
	void Simulation();
	void startEngine(Engine&);
	void stopEngine(Engine&);

	void changeEngineBlock();
	void repairEngine();
	void fullThrottle(int);
	void addFuelTank(double, vector<Tank*>&);
	void listFuelTanks();
	void printFuelTankCount();
	void removeFuelTank(int);
	void connectFuelTankToEngine(int);
	void disconnectFuelTankFromEngine(int);
	void listConnectedTanks();
	void printTotalFuelQuantity();
	void printTotalConsumedFuelQuantity();
	void printTankInfo(int);
	void fillTank(int, double);

	void openValve(int);
	void closeValve(int);

	void breakFuelTank(int);
	void repairFuelTank(int);

	void AddAndTrans(int, int, int);

	void wait(int);
	void stopSimulation();

	int stringParser(string&);

	void consumeFuel();
	vector<Tank*>::iterator returnTank(vector<Tank*>&, int);
private:
	vector<Tank*>listOfTanks;
	int totalTime = 0;
	double totalConsumedFuel = 0;
	ifstream inputFile;
	ofstream outputFile;
};
#endif // !_COMMANDS_H