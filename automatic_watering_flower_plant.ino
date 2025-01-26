#include<Arduino.h>
#include<LiquidCrystal.h>
#include<Servo.h>

#define servopin 0
#define redpin 8
#define greenpin 9

LiquidCrystal lcd(12,11,5,4,3,2);
Servo valve;

int moistRead;
int moistperc;
int valveangle;
int valveperc;

void setup() {
lcd.begin(16,2);
lcd.clear();
valve.attach(servopin);
valve.write(0);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);  
  

}

void loop() {
  moistRead=analogRead(0);
  moistperc=map(moistRead,980,290,0,100);
  lcd.setCursor(0,0);
  lcd.print("Moisture=");
  lcd.print(moistperc);
  lcd.print("%");
  valveangle=map(moistperc,60,0,0,180);
  valveperc=map(moistangle,0,180,0,100);
  lcd.setCursor(0,1);
  if(valveperc>0){
    valve.write(valveangle);
    lcd.print("valve");
    lcd.print(valveperc);
    lcd.print("%");
    lcd.print("open");

    digitalWrite(redpin,HIGH);
    digitalWrite(greenpin,LOW);
  }else{
    valve.write(0);
    lcd.print("Not Watering");
    digitalWrite(redpin,LOW);
    digitalWrite(greenpin,HIGH);
  }
  delay(50);
  lcd.clear();

}
