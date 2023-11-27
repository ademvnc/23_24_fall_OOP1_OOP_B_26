#include "Student.h"
#include "Clock.h"

#include <iostream>
using namespace std;


void test(Developer1::CClock& myClock); // test fonskiyonunu tanımladık

/*
 * Question1: Fix the code and compile it */ //DONE
int main() {

	Developer1::CClock myClock; // CClock sınıfını Developer1 isim alanından kullandık

	Developer1::CClock yourClock(3, 50);

	{
	Developer1::CClock clock(1, 1, 1);

	}

	Developer2::Student student; // Student sınıfını Developer2 isim alanından kullandık

	student.setStudent("Ali", 123456);

	student.print();
	myClock.setTime(7, 15, 25);

	// test fonksiyonunu çağırarak isTimeBlocked'ı kullanalım
    test(myClock);

	return 0;
}


void test(){
	Developer1::CClock myClock(3,60); // CClock sınıfını Developer1 isim alanından kullandık
	/* Question2: Block the changing hour and minute values of above object.
	 * Do not remove or change main function implementation */  //DONE
	// myClock.incrementHours();
	// myClock.incrementMinutes();
	myClock.blockTimeChange(); // Saat ve dakika değişimini bloke ediyoruz
	myClock.incrementSeconds();
	myClock.printTime();

	Developer1::CClock clock1(1, 1, 1);
	Developer1::CClock clock2(1, 1, 1);
	clock1.incrementHours();
	clock1.incrementSeconds();
	/* Question3: Compare clock1 and clock2 objects and print if they are equal or not. */  //DONE	
	if (clock1.equalTime(clock2))
        cout << "clock1 and clock2 are equal." << endl;
    else
        cout << "clock1 and clock2 are not equal." << endl;

	/* Question4: Add a timeZone variable whcih can not be changed by anyone.
	 * timezone default value is "GMT+3" */ //DONE
	 cout << "Time Zone: " << myClock.getTimeZone() << endl; // Saat dilimini yazdırıyoruz 
	/* Question5: Overload the incrementSeconds method to increment second value as given parameter */ //DONE
		 myClock.incrementSeconds(5); // 5 saniye arttırıyoruz
}

/*
 * Question6: Review the code and fix the bugs  //DONE	
 */

