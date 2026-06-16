#include <Adafruit_LiquidCrystal.h>

int seconds = 0;

Adafruit_LiquidCrystal lcd_1(0);
const int sensorPin = A1;
const int powerPin = A0;
const int motorPin = 7;
void setup(){
  pinMode(powerPin , OUTPUT);
pinMode(motorPin , OUTPUT);
  lcd_1.begin(16, 2);

  lcd_1.print("system active");
  delay(1500);
  lcd_1.clear();
}

void loop()
{
  digitalWrite(powerPin , HIGH);
  delay(10);
  int moistureValue = analogRead(sensorPin);
  int moisturePercent = map(moistureValue , 0 ,1023,0, 100);
  digitalWrite(powerPin, LOW);
  
  lcd_1.setCursor(0, 0);
  lcd_1.print(moisturePercent);
  lcd_1.print("%");
  delay(200);
  lcd_1.setCursor(0, 1);
  if (moisturePercent< 35){
   
  digitalWrite(motorPin , HIGH);
   
    
}
  
  else{
    
    digitalWrite(motorPin,LOW);
  }
}