#include "Clock.h"

#include <iostream>
using namespace std;
namespace Developer1{
void CClock::setTime(int hours, int minutes, int seconds)
{
	if (0 <= hours && hours < 24)
		hr = hours;
	else
		hr = 0;

	if (0 <= minutes && minutes < 60)
		min = minutes;
	else
		min = 0;
	
	if (0 <= seconds && seconds < 60)
		sec = seconds;
	else
		sec = 0;
}



 // Fonksiyonu time blocklandığında çağırmayarak saat ve dakika değişimini engelleyebiliriz
    void CClock::incrementHours() {
        if (!isTimeBlocked) {
            hr++;
            if (hr > 23)
                hr = 0;
        }
    }

  // Fonksiyonu time blocklandığında çağırmayarak saat ve dakika değişimini engelleyebiliriz
    void CClock::incrementMinutes() {
        if (!isTimeBlocked) {
            min++;
            if (min > 59) {
                min = 0;
                incrementHours(); // Saati bir saat arttır
            }
        }
    }

void CClock::incrementSeconds()
{	
	if (!isTimeBlocked) {
		sec++;
		if (sec > 59){
			sec=0;
			incrementMinutes(); //increment minutes
		}
	}
	
}
   // isTimeBlocked üye değişkenini başlangıç değeriyle tanımlıyoruz
    bool CClock::isTimeBlocked = false;
	
   // Yeni bir fonksiyon ekleyerek saat ve dakika değişimini bloke edebiliriz
    void CClock::blockTimeChange() {
        isTimeBlocked = true;
    }

	 // Eğer zaman değişimi bloke edilmediyse, true döner
    bool CClock::isTimeChangeBlocked() const {
        return isTimeBlocked;
    }


bool CClock::equalTime(const CClock& otherClock) const
{
	return (hr == otherClock.hr
		&& min == otherClock.min
		&& sec == otherClock.sec);

}

void CClock::printTime()
{
	if (hr <10)
		cout << "0";
	cout << hr <<":";
	if (min <10)
		cout << "0";
	cout << min <<":";
	if (sec <10)
		cout << "0";
	cout << sec ;
}
}
