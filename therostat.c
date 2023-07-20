#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 6, 5, 4, 3);



//  Variables

volatile int Signal;                // holds the received data

static boolean serialVisual = true;   // To see Arduino Serial Monitor ASCII Visual Pulse


void setup()

{

  lcd.begin(16, 2);
  
  Serial.begin(115200);   

  interruptSetup();

  lcd.clear();

  lcd.setCursor(0,0);

  lcd.print("Digital Thermostat");

  delay(5000);

  lcd.clear();

  lcd.setCursor(0,0);

  lcd.print("Getting Data!!");

  delay(2000);

}


void loop()

{

  serialOutput();  

  delay(20); 

  read_temp();

}


void interruptSetup()

{     

  TCCR2A = 0x02;    

  TCCR2B = 0x06;    

  OCR2A  = 0X7C;      

  TIMSK2 = 0x02;

  sei();         

} 


void serialOutput()

{  

 if (serialVisual == true)

  {  

     arduinoSerialMonitorVisual('-', Signal);   // Makes Serial Monitor Visualizer

  } 

 else

  {

      sendDataToSerial('S', Signal);    

   }        

}



void arduinoSerialMonitorVisual(char symbol, int data )

{    

  const int sensorMin = 0;      // sensor minimum

  const int sensorMax = 1024;    // sensor maximum

  int sensorReading = data;

  int range = map(sensorReading, sensorMin, sensorMax, 0, 11);


  switch (range) 

  {

    case 0:     

      Serial.println("");   

      break;

    case 1:   

      Serial.println("-");

      break;

    case 2:    

      Serial.println("--");

      break;

    case 3:    

      Serial.println("---");

      break;

    case 4:   

      Serial.println("----");

      break;

    case 5:   

      Serial.println("-----");

      break;

    case 6:   

      Serial.println("------");

      break;

    case 7:   

      Serial.println("-------");

      break;

    case 8:  

      Serial.println("--------");

      break;

    case 9:    

      Serial.println("---------");

      break;

    case 10:   

      Serial.println("----------");

      break;

    case 11:   

      Serial.println("-----------");

      break;

  } 

}



void sendDataToSerial(char symbol, int data )

{

   Serial.print(symbol);

   Serial.println(data);                

}


void read_temp()

{

  int temp_val =  analogRead(A1);

  float mv = (temp_val/1024.0)*5000; 

  float temp = mv/10;

  float constant_temp = 22.5;

  float difference;

  Serial.print("Temperature:");
  Serial.println(temp);

  if (temp > constant_temp)
  
  {
    difference = temp - constant_temp;

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp.:");
    lcd.setCursor(7,0);
    lcd.print(temp);
    lcd.setCursor(13,0);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Temp dec by ");
    lcd.setCursor(13,1);
    lcd.print(difference);
  }
  else if (temp < constant_temp)
  
  {
    difference = constant_temp - temp;

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp.:");
    lcd.setCursor(7,0);
    lcd.print(temp);
    lcd.setCursor(13,0);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Temp inc by ");
    lcd.setCursor(13,1);
    lcd.print(difference);
  }
  else
  
  {

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp.:");
    lcd.setCursor(7,0);
    lcd.print(temp);
    lcd.setCursor(13,0);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Temp normal");
  }

}