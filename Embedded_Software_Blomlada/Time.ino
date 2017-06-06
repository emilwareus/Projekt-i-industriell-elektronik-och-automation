#include <DS3231.h>

DS3231  rtc(SDA, SCL);
//http://www.rinkydinkelectronics.com/library.php?id=73

void setupClock() { 

 rtc.begin(); // Initialize the rtc object
 //rtc.setTime(14, 6, 2);
 //rtc.setDate(5, 6, 2017);

}


String getRTime(){
  return rtc.getTimeStr(); 
}

String getRDate(){
  return rtc.getDateStr();
}

void PrintDT(){
  Serial.print(rtc.getDateStr());
  Serial.print("\t");
  Serial.print(rtc.getTimeStr());
  Serial.print("\t");
}


