#include <DHT.h>
#include<LiquidCrystal.h>
#define DHTPIN A0
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(2,3,4,5,6,7); // (lcd pin RW,EN,D4,D5,D6,D7)

int FanPin=12; // connect to the relay signal pin to control fan on off

float temp;
int SetTemp=32;  //Set your threshold temperature
void setup()
{
 Serial.begin(9600);  //
 lcd.begin(16,2);
 dht.begin();
 pinMode(FanPin,OUTPUT);
 digitalWrite(FanPin,HIGH); //Initially Fanpin High because Relay module active LOW
}
void loop ()

{
  temp = dht.readTemperature();
  
  Serial.println(temp);
  lcd.setCursor(0,0);
  lcd.print ("Temp:");
  lcd.print(temp); 
  lcd.print((char)223);// for degree sign
  lcd.print("C");

  if (temp >= SetTemp) //
  {
  digitalWrite(FanPin, LOW); // Relay module active LOW
  lcd.setCursor(0,1);
  lcd.print("Fan:");
  lcd.print("ON");
   }
  else
  {
  digitalWrite(FanPin, HIGH);
  lcd.setCursor(0,1);
  lcd.print("Fan:");
  lcd.print("0FF");
}
delay(1000);
lcd.clear();
}
