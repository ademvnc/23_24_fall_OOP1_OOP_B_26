/**
 * @file commands.cpp
 * @brief This file contains the implementation of the Commands class.
 * @details This file contains the implementation of the Commands class.
 *          The Commands class is responsible for reading the input file and executing the commands in the input file.
 *          The Commands class is also responsible for printing the outputs to the output file.
 *          The Commands class is also responsible for creating the Engine object and the ExternalTank objects, InternalTank object, Valve objects.
 *          The Commands class is also responsible for creating the observers and registering them to the subject.
 * @author ademvnc beytullahorhan
 * @date 12/11/2023
 * @version 1.0
 * @note This code is an assignment of Object Oriented Programming Lab 1, TakeHome4 on 2023 Fall Semester. 
 *        
 * 
*/


#include "commands.h"
#include"SimulationData.h"

SimulationData sd; //!!Subject

using namespace std;
Engine* Engine::instance = 0; //!!static initialize.

typedef vector<Tank*> vecTank; //!!Typedef.
Engine* e = e->getInstance(); //!!Singleton. get instance.

void Commands::Simulation()
{
	sd.registerObserver(e); //!!Motoru observer listesine ekler.
	sd.registerObserver(e->getITank()); //!!Internal Tank'i, observer listesine ekler.
	sd.registerObserver(e->getITank()->getValve()); //!!Internal Tank'in valvesini observer listesine ekler.
	listOfTanks.push_back(e->getITank()); //!!Internal Tank'i, tank listesine ekler.
	try
	{
		outputFile.open("output.txt");

		string fileName;
		cout << "Please enter the input file name(with file extension): ";
		cin >> fileName;
		inputFile.open(fileName);
		if (!inputFile.is_open()) //!!Input file cannot be opened.
			throw (string)"(Error: Input File)\nError Message: Input File cannot be found.";

		string cmd;
		getline(inputFile, cmd);
		string rawCmd;

		while (true)
		{
			rawCmd = cmd.substr(0, cmd.find(' '));
			if (rawCmd == "start_engine;")
			{
				startEngine(*e);
				wait(1);
			}
			else if (rawCmd == "stop_engine;")
			{
				stopEngine(*e);
				//!durdu�u i�in wait yok.
			}
			else if (rawCmd == "change_engine_block;")
			{
				changeEngineBlock();
			}
			else if (rawCmd == "repair_engine;")
			{
				repairEngine();
			}
			else if (rawCmd == "full_throttle")
			{
				int seconds;
				seconds = stringParser(cmd);
				fullThrottle(seconds);
				wait(seconds);
				e->setFuelPerSecond(e->getFuelPerSecond() / 5);
			}
			else if (rawCmd == "add_fuel_tank")
			{
				double capacity;
				capacity = stringParser(cmd);
				addFuelTank(capacity, listOfTanks);
				wait(1);
			}
			else if (rawCmd == "list_fuel_tanks;")
			{
				listFuelTanks();
				wait(1);
			}
			else if (rawCmd == "print_fuel_tank_count;")
			{
				printFuelTankCount();
				wait(1);
			}
			else if (rawCmd == "remove_fuel_tank")
			{
				int TankId = stringParser(cmd);
				removeFuelTank(TankId);
				wait(1);
			}
			else if (rawCmd == "connect_fuel_tank_to_engine")
			{
				int TankId = stringParser(cmd);
				connectFuelTankToEngine(TankId);
				wait(1);
			}
			else if (rawCmd == "disconnect_fuel_tank_from_engine")
			{
				int TankId = stringParser(cmd);
				disconnectFuelTankFromEngine(TankId);
				wait(1);
			}
			else if (rawCmd == "list_connected_tanks;")
			{
				listConnectedTanks();
				wait(1);
			}
			else if (rawCmd == "print_total_fuel_quantity;")
			{
				printTotalFuelQuantity();
				wait(1);
			}
			else if (rawCmd == "print_total_consumed_fuel_quantity;")
			{
				printTotalConsumedFuelQuantity();
				wait(1);
			}
			else if (rawCmd == "print_tank_info")
			{
				int TankId = stringParser(cmd);
				printTankInfo(TankId);
				wait(1);
			}
			else if (rawCmd == "fill_tank")
			{
				int TankId = stringParser(cmd); //!!ilk önce id. Sonra quantityi verecek
				double quantity = stringParser(cmd);
				fillTank(TankId, quantity);
				wait(1);
			}
			else if (rawCmd == "open_valve")
			{
				int TankId = stringParser(cmd);
				openValve(TankId);
				wait(1);
			}
			else if (rawCmd == "close_valve")
			{
				int TankId = stringParser(cmd);
				closeValve(TankId);
				wait(1);
			}
			else if (rawCmd == "break_fuel_tank")
			{
				int TankId = stringParser(cmd);
				breakFuelTank(TankId);
				wait(1);
			}
			else if (rawCmd == "repair_fuel_tank")
			{
				int TankId = stringParser(cmd);
				repairFuelTank(TankId);
				wait(1);
			}
			else if (rawCmd == "sum_operator")
			{
				int toBeFilled = stringParser(cmd);
				int toBeFDrained = stringParser(cmd);
				int toBeSDrained = stringParser(cmd);
				AddAndTrans(toBeFilled, toBeFDrained, toBeSDrained);
				wait(1);
			}
			else if (rawCmd == "wait")
			{
				int seconds = stringParser(cmd);
				wait(seconds);
			}
			else if (rawCmd == "stop_simulation;")
			{
				stopSimulation();
				break;
			}
			else if (cmd == "") //!!Null Command
			{
				throw (string)"(Error: Null Command)\nError Message: You entered Null Command.";
			}
			else //!!Undefined Command
			{
				throw (string)"(Error: Undefined Command)\nError Message: '" + cmd + "' this command is not in the command list.";
			}
			getline(inputFile, cmd);
		}
	}
	catch (string& msg)
	{
		//!!"Program is shutting down" yazisi degistirilebilir.
		cout << msg << " Please try again!\nProgram is shutting down..." << endl;
		outputFile << msg << " Please try again!\nProgram is shutting down..." << endl;
		outputFile.close(); //!!dosya kapatildi.
	}
}
//!!Motoru başlatan komut.   (Motor zaten çalışıyorsa farklı bir output yazdıracak.)
void Commands::startEngine(Engine& e)
{
	if (!e.getStatus())
	{
		if (e.ConnectedTanks.size() > 0)//!! Motorun bağlı tankı varsa.
		{
			if (e.getQuantityOfInternalTank() > 0 && e.getHealth() > 20)
			{
				e.setStatus(true);
				outputFile << "Engine has been started." << endl << endl;
			}
			else
			{
				outputFile << "Fuel quantity of Internal Tank is: 0. The engine couldn't start." << endl << endl;
			}
		}
		else
		{
			outputFile << "There is no connected tank to engine. The engine couldn't start." << endl << endl;
			return;
		}
	}
	else
		outputFile << "Engine is already turned on." << endl << endl;
}
//!Motoru kapatan komut. (Motor zaten kapal�ysa farkl� bir output yazd�racak.)
void Commands::stopEngine(Engine& e)
{
	if (e.getStatus())
	{
		e.setStatus(false);
		outputFile << "Engine has been stopped." << endl << endl;
	}
	else
		outputFile << "Engine is already off. " << endl << endl;
}
void Commands::changeEngineBlock()
{
	if (!e->getStatus()) //! Motor çalışmıyorsa.
	{
		if (e->getHealth() == 0) //! Motorun sağlığı 0 ise.
		{
			e->setHealth(100);
			e->setHeat(20);
			e->setFuelPerSecond(5.5);
			if (e->isFullThrottle()) //! Motor full throttle ise
			{
				e->setFullThrottle(false);
				e->setFuelPerSecond(e->getFuelPerSecond() / 5);
			}
			outputFile << "Engine block has successfully changed." << endl << endl;
		}
	}
}
void Commands::repairEngine()
{
	//!Engine can be repaired if health is NOT 0 percent.
	if (!e->getStatus()) //!calismiyor.
	{
		if (e->getHealth() > 0) //!0 de�ilse repair et.
		{
			e->setHealth(100);
			outputFile << "Engine has been repaired." << endl << endl;
		}
	}
	else //calisiyor.
	{
		outputFile << "Engine is running. Cannot repair it! Please turn off the engine." << endl << endl;
	}
}
void Commands::fullThrottle(int seconds)
{
	if (e->getStatus())
	{
		if (!e->isFullThrottle())
		{
			e->setFullThrottle(true);
			e->setFuelPerSecond(e->getFuelPerSecond() * 5);
			outputFile << "Full Throttling for " << seconds << " seconds." << endl << endl;
		}
	}
}
void Commands::addFuelTank(double capacity, vecTank& listOfTanks)
{
	ExternalTank* newTank = new ExternalTank(capacity);
	sd.registerObserver(newTank);
	sd.registerObserver(newTank->getValve());
	listOfTanks.push_back(newTank);
	outputFile << "A new tank added in the list. TankID: " << newTank->getTankID() << endl << endl;
}
void Commands::listFuelTanks()
{
	outputFile << "------List Of Fuel Tanks------" << endl;
	vecTank::iterator it;
	for (it = listOfTanks.begin(); it < listOfTanks.end(); it++)
	{
		outputFile << " Tank ID: " << (*it)->getTankID() << endl;
	}
	outputFile << "------------------------------" << endl << endl;
}
void Commands::printFuelTankCount()
{
	outputFile << "Fuel tank count is: " << listOfTanks.size() << endl << endl;
}
void Commands::removeFuelTank(int TankId)
{
	vecTank::iterator it = returnTank(listOfTanks, TankId);
	vecTank::iterator it2 = returnTank(e->ConnectedTanks, TankId);
	if ((*it)->getValveStatus()) 
	{
		outputFile << "Valve is open. Tank couldn't be removed." << endl << endl;
	}
	else
	{
		sd.removeObserver(*it); //!Observer listesinden kaldiriyor.
		sd.removeObserver((*it)->getValve());
		delete (*it);
		listOfTanks.erase(it);
		listOfTanks.resize(listOfTanks.size());

		//!connected tank ise ordan da kald�r.
		if (it2 != e->ConnectedTanks.end())
		{
			e->ConnectedTanks.erase(it2);
			e->ConnectedTanks.resize(e->ConnectedTanks.size());
		}
	}
}
void Commands::connectFuelTankToEngine(int TankId)
{
	if (TankId == 0)
	{
		outputFile << "'ID: 0' is dedicated for Engine's internal tank. Please try again with different ID." << endl;
		return;
	}

	vecTank::iterator it = returnTank(listOfTanks, TankId);
	if (it != listOfTanks.end())
	{
		e->ConnectedTanks.push_back(*it);
	}
	else
	{
		outputFile << "No Tank found that matches the Tank ID you entered. You entered(Tank ID): " << TankId << endl;
	}
}
void Commands::disconnectFuelTankFromEngine(int TankId)
{
	//!If a fuel tanks valve is open, that tank cant be removed.
	if (TankId == 0)
	{
		outputFile << "'ID: 0' is dedicated for Engine's internal tank. Please try again with different ID." << endl;
		return;
	}
	vecTank::iterator it = returnTank(e->ConnectedTanks, TankId);

	if (it != e->ConnectedTanks.end()) //! bulunduysa
	{
		if ((*it)->getValveStatus()) //! vana aciksa
		{
			outputFile << "Cannot Disconnect Tank. Tank's valve is open. Tank ID: " << TankId << endl;
		}
		else //! vana kapalıysa
		{
			e->ConnectedTanks.erase(it);
			e->ConnectedTanks.resize(e->ConnectedTanks.size());
		}
	}
}
void Commands::listConnectedTanks()
{
	outputFile << "------List Of Connected Tanks------" << endl;
	vecTank::iterator it;
	for (it = e->ConnectedTanks.begin(); it < e->ConnectedTanks.end(); it++)
	{
		outputFile << " Tank ID: " << (*it)->getTankID() << endl;
	}
	outputFile << "-----------------------------------" << endl << endl;
}
void Commands::printTotalFuelQuantity()
{
	double totalFuel = 0;
	totalFuel += e->getQuantityOfInternalTank();
	vecTank::iterator it;
	for (it = listOfTanks.begin(); it < listOfTanks.end(); it++)
	{
		totalFuel += (*it)->getFuelQuantity();
	}
	outputFile << "Total Fuel Quantity: " << totalFuel << endl << endl;
}
void Commands::printTotalConsumedFuelQuantity()
{
	outputFile << "Total Consumed Fuel Quantity is: " << totalConsumedFuel << endl << endl;
}
void Commands::printTankInfo(int TankId)
{
	vecTank::iterator it;
	for (it = listOfTanks.begin(); it < listOfTanks.end(); it++)
	{
		if ((*it)->getTankID() == TankId)
		{
			outputFile << "------PRINT TANK INFO------" << endl;
			outputFile << " Tank's ID: " << (*it)->getTankID() << endl;
			outputFile << " Tank's fuel quantity is: " << (*it)->getFuelQuantity() << endl;
			outputFile << " Tank's capacity is: " << (*it)->getCapacity() << endl;
			outputFile << " Is tank broken: "; (*it)->IsBroken() ? outputFile << "Yes" << endl : outputFile << "False" << endl;;
			outputFile << " Is tank's valve open: "; (*it)->getValveStatus() ? outputFile << "Yes" << endl : outputFile << "False" << endl;
			outputFile << "---------------------------" << endl << endl;
		}
	}
}
void Commands::fillTank(int TankId, double quantity)
{
	vecTank::iterator it = returnTank(listOfTanks, TankId);
	double bfFuel;
	if (it != listOfTanks.end()) //! bulunduysa
	{
		bfFuel = (*it)->getCapacity() - (*it)->getFuelQuantity(); //! tanktaki bos alan
		if (quantity >= bfFuel)
		{
			(*it)->setFuelQuantity((*it)->getCapacity());
		}
		else
		{
			(*it)->setFuelQuantity(quantity + (*it)->getFuelQuantity());
		}
		outputFile << "Tank " << TankId << " filled." << endl << endl;
	}
}
void Commands::openValve(int TankId)
{
	double bufferFuel = 0;
	vecTank::iterator it;
	for (it = e->ConnectedTanks.begin(); it < e->ConnectedTanks.end(); it++)
	{
		if ((*it)->getTankID() == TankId)
		{
			if ((*it)->getValveStatus() == false)
			{
				(*it)->setValveStatus(true); //! valveyi ac.
				outputFile << "Tank " << TankId << "'s valve has opened." << endl << endl;
			}
			if (e->getQuantityOfInternalTank() < 20) //! internal tanktaki fuel 20nin altındaysa
			{
				if ((*it)->getFuelQuantity() != 0) //! tanktaki fuel 0 degilse
				{
					double bfr = 0;
					bfr = 55 - e->getQuantityOfInternalTank();
					if (bfr == 0)
					{

					}
					else if (bfr >= (*it)->getFuelQuantity())
					{
						//kapasite 55
						//içinde olan 25
						//!bfr 30
						//!gelen 25
						e->setQuantityOfInternalTank(e->getQuantityOfInternalTank() + (*it)->getFuelQuantity());
						(*it)->setFuelQuantity(0);
					}
					else if (bfr < (*it)->getFuelQuantity())
					{
						//!kapasite 55
						//! içinde olan 45
						//! bfr 10
						//! gelen 100
						e->setQuantityOfInternalTank(55);
						(*it)->setFuelQuantity((*it)->getFuelQuantity() - bfr);
					}

				}
			}
			break;
		}
	}
}
void Commands::closeValve(int TankId)
{
	vecTank::iterator it;
	for (int i = 0; i < listOfTanks.size(); i++)
	{
		if (listOfTanks[i]->getTankID() == TankId)
		{
			if (listOfTanks[i]->getValveStatus()) //!acik
			{
				listOfTanks[i]->setValveStatus(false);
				outputFile << "Tank " << TankId << "'s valve has closed." << endl << endl;
			}
		}	
	}
}
void Commands::breakFuelTank(int TankId)
{
	outputFile << "Tank " << TankId << " is broken." << endl << endl;
	vecTank::iterator it = returnTank(listOfTanks, TankId);
	if (it != listOfTanks.end())
	{
		if (!(*it)->IsBroken()) (*it)->setStatus(true); //! bozuk değilse boz.
	}
}
void Commands::repairFuelTank(int TankId)
{
	outputFile << "Tank " << TankId << " has been repaired." << endl << endl;
	vecTank::iterator it = returnTank(listOfTanks, TankId);
	if (it != listOfTanks.end())
	{
		if ((*it)->IsBroken()) (*it)->setStatus(false); //! bozuk ise tamir et.
	}
}
void Commands::AddAndTrans(int ToBeFilled, int ToBeFDrained, int ToBeSDrained)
{
	vecTank::iterator fTank = returnTank(listOfTanks, ToBeFilled);
	vecTank::iterator sTank = returnTank(listOfTanks, ToBeFDrained);
	vecTank::iterator tTank = returnTank(listOfTanks, ToBeSDrained);


	ExternalTank secTank((*sTank)->getCapacity());
	secTank.setFuelQuantity((*sTank)->getFuelQuantity());

	ExternalTank thrTank((*tTank)->getCapacity());
	thrTank.setFuelQuantity((*tTank)->getFuelQuantity());
	//! ilk tanktaki bos alani verecek.
	int buffer = (*fTank)->getCapacity() - (*fTank)->getFuelQuantity();
	if (buffer >= (*sTank)->getFuelQuantity() + (*tTank)->getFuelQuantity()) //! yeterli alan var.
	{
		(*sTank)->setFuelQuantity(0); //! Drained
		(*tTank)->setFuelQuantity(0); //! Drained
		ExternalTank buf = secTank + thrTank;
		(*fTank)->setFuelQuantity(buf.getCapacity());
		outputFile << "Tank " << ToBeFilled << " filled by Tank " << ToBeFDrained << " and Tank " << ToBeSDrained << endl << endl;
	}
}
//!consume islemini burda yap.
void Commands::wait(int seconds)
{
	if (e->getStatus())//!motor �al���yor
	{
		for (int i = 0; i < seconds; i++)
		{
			consumeFuel();
		}
		e->EngineHeatUp(seconds);
		totalTime += seconds;
	}
	else
	{
		e->EngineCoolDown();
	}
}
void Commands::stopSimulation()
{
	//!Observer mesajlarını burda yazmamız lazım.
	sd.setMessage("Simulation Stopped"); //! notify icinde zaten
	listOfTanks.clear();
	e->ConnectedTanks.clear();
	delete e;
	cout << "Simulation has successfully stopped." << endl;
	cout << "Outputs are printed in 'output.txt' file." << endl;
	outputFile << "Simulation has successfully stopped.";
	outputFile.close();
}
int Commands::stringParser(string& str)
{
	int flag = 0;
	int posX = 0;
	//!int posY = 0;
	string sub;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')//! boşluk var
		{
			if (flag == 0) posX = i;
			flag++;
		}
	}
	if (flag == 0)
	{
		return stoi(str);
	}
	else if (flag == 1) //! ADD 5
	{
		if (str[0] >= 48 && str[0] <= 57)
		{
			int buf = str[0] - '0';
			str = str.erase(0, posX + 1);
			return buf;
		}
		else
		{
			str = str.erase(0, posX + 1);
			//! int s vardi.
			return stoi(str);
		}
	}
	else if (flag == 2)
	{
		sub = str.substr(posX, posX + 1);
		str.erase(0, posX + 2);
		return stoi(sub);
	}
	else if (flag == 3) //! ADD 5 3 2
	{
		sub = str.substr(posX, posX + 1);
		str.erase(0, posX + 3);
		return stoi(sub);
	}
}
void Commands::consumeFuel()
{
	if (e->getQuantityOfInternalTank() < 20) //!internal tankın fueli 20in altına düştüyse
	{
		vecTank::iterator it;
		for (it = e->ConnectedTanks.begin(); it < e->ConnectedTanks.end(); it++)
		{
			if ((*it)->getFuelQuantity() >= e->getFuelPerSecond())
			{
				//!open valve içinde de var. Optimize edilebilir.
				double bfr = 0;
				bfr = 55 - e->getQuantityOfInternalTank();
				if (bfr == 0)
				{

				}
				else if (bfr >= (*it)->getFuelQuantity())
				{
					//!kapasite 55
					//içinde olan 25
					//!bfr 30
					//!gelen 25
					e->setQuantityOfInternalTank(e->getQuantityOfInternalTank() + (*it)->getFuelQuantity());
					(*it)->setFuelQuantity(0);
				}
				else if (bfr < (*it)->getFuelQuantity())
				{
					//!kapasite 55
					// içinde olan 45
					//! bfr 10
					//! gelen 100
					e->setQuantityOfInternalTank(55);
					(*it)->setFuelQuantity((*it)->getFuelQuantity() - bfr);
				}
				break;
			}
		}
	}
	//!5.5 harca
	//!full throttleda 5.5*5 
	//!normalde 5 harcayacak �ekilde g�ncelle.
	e->setQuantityOfInternalTank(e->getQuantityOfInternalTank() - e->getFuelPerSecond());
	totalConsumedFuel += e->getFuelPerSecond();

}
vector<Tank*>::iterator Commands::returnTank(vector<Tank*>& vectorTank, int TankID)
{
	vecTank::iterator it;
	for (it = vectorTank.begin(); it < vectorTank.end(); it++)
	{
		if ((*it)->getTankID() == TankID)
		{
			return it;
		}
	}
	return vectorTank.end();
}