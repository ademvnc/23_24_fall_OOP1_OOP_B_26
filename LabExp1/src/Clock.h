#pragma once

#include <iostream>
using namespace std;

namespace Developer1{
class CClock {				//Declaration of class CClock
public:
	void setTime(int, int, int);
	void getTime(int &hours, int &minutes, int &seconds) const{
		hours = hr;
		minutes = min;
		seconds = sec;
	}
	void printTime();
	void incrementSeconds();
	void incrementMinutes();
	void incrementHours();
	void blockTimeChange();
	bool isTimeChangeBlocked() const;
	const std::string getTimeZone() const { return timeZone; }
	bool equalTime (const CClock&) const;
	void incrementSeconds(int seconds);
	
	CClock(long miliseconds){
		hr = miliseconds / 1000 / 3600;
		min = miliseconds / 1000 / 60;
		sec = miliseconds / 1000 / 1;
	}

	CClock(int hours=0, int minutes=0, int seconds=0){
		setTime(hours,minutes,seconds);
	}
	
	~CClock(){
		cout<<"";
		cout<<endl<<"Destructor:";
		printTime();
	}

	 

	 
	
private:
	int hr;
	int min;
	int sec;
	const string timeZone = "GMT+3"; // Time zone ekledik
	static bool isTimeBlocked; // isTimeBlocked'ı static olarak tanımlıyoruz
};
}
