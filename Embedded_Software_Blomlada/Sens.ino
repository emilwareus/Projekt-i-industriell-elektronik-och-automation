int Moist_pin0 = A0;
int Moist_pin1 = A1; 
int Moist_pin2 = A2; 
int Moist_pin3 = A3;  
int output_Moist[4] ;


/*
 * This Method reads the Moist values from A0..A3 
 * The Values are stored in vector output_Moist[]
 */
void ReadMoist(){

  //Reading Moist Values into output vector and maps them into 0-100 values
  output_Moist[0]= analogRead(Moist_pin0);
  output_Moist[0] = map(output_Moist[0],550,0,0,100);
  output_Moist[1]= analogRead(Moist_pin1);
  output_Moist[1] = map(output_Moist[1],550,0,0,100);
  output_Moist[2]= analogRead(Moist_pin2);
  output_Moist[2] = map(output_Moist[2],550,0,0,100);
  output_Moist[3]= analogRead(Moist_pin3);
  output_Moist[3] = map(output_Moist[3],550,0,0,100);

}


/*
 * Prints the Output_Moist[] vector to the serial monitor
 */
 String PrintMoist(){
  String s;
  Serial.print("Mositure of pin 1..4 : ");
  for(int i = 0; i<4 ; i++){
    Serial.print("\t");
    Serial.print(output_Moist[i]);
    Serial.print("%");

    s = s + output_Moist[i];
    s = s + "\t";
  }
  Serial.println(" ");

  return s;
}




int I1=2, I2=3, I3=4, I4=5;
float Time_Water[4];
bool Water[4];
void controlSetup(){
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
  
}



void CheckWater(int TH){
   if(output_Moist[0]<TH){
    Time_Water[0]=millis();
    digitalWrite(I1, HIGH);
    Water[0]=true;
    Serial.println("Time to water I1");
   }
   if(output_Moist[1]<TH){
    Time_Water[1]=millis();
    digitalWrite(I2, HIGH);
    Water[1]=true;
    Serial.println("Time to water I2");
   }
   if(output_Moist[2]<TH){
    Time_Water[2]=millis();
    Serial.println(Time_Water[2]);
    digitalWrite(I3, HIGH);
    Water[2]=true;
    Serial.println("Time to water I3");
   }
   if(output_Moist[3]<TH){
    Time_Water[3]=millis();
    digitalWrite(I4, HIGH);
    Water[3]=true;
    Serial.println("Time to water I4");
   }
}

void DoWater(float t) {
   float t0 = millis();
   if(Time_Water[0]<(t0-t*1000) && Water[0]==true){
    digitalWrite(I1, LOW);
    Serial.print("Stop Watering I1   Sec: ");
    Serial.println((Time_Water[0]-t0));
    Water[0]=false;
   }
   if(Time_Water[1]<(t0-t*1000)&& Water[1]==true){
    digitalWrite(I2, LOW);
    Serial.print("Stop Watering I2   Sec: ");
    Serial.println((Time_Water[1]-t0));
    Water[1]=false;
   }
   if((Time_Water[2]<(t0-t*1000))&& Water[2]==true){
    digitalWrite(I3, LOW);
    Serial.print("Stop Watering I3   Sec: ");
    Serial.println((Time_Water[1]-t0));
    Water[2]=false;
   }
   if(Time_Water[3]<(t0-t*1000)&& Water[3]==true){
    digitalWrite(I4, LOW);
    Serial.print("Stop Watering I4   Sec: ");
    Serial.println((Time_Water[3]-t0));
    Water[3]=false;
   }
}




