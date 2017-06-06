
void setup() {
  Serial.begin(9600);

  setupClock();
  controlSetup();
  
  Serial.println("Reading From the Sensor ...");
  delay(2000);
  }



void loop() {
  /*
   
  if (!Rtc.IsDateTimeValid()) 
    {
        // Common Cuases:
        //    1) the battery on the device is low or even missing and the power line was disconnected
        Serial.println("RTC lost confidence in the DateTime!");
    }
 */
  ReadMoist();
  PrintDT();
  PrintMoist();
  CheckWater(55);
  DoWater(10);
  Serial.println();
  delay(1000);
  }




