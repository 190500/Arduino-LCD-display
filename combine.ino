
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3,POSITIVE); 
int state=LOW;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
lcd.backlight();
pinMode(D3,OUTPUT);
digitalWrite(D3,state);
pinMode(D4,OUTPUT);
digitalWrite(D4,~state);
pinMode(D8,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  lcd.setCursor(2,0);//Defining positon to write from first row,first column .
  if(digitalRead(D8)==HIGH)
  {
    
    digitalWrite(D3,state);
    digitalWrite(D4,~state);
    state=~state;
    if(digitalRead(D3)== HIGH)
    {lcd.print("LED 1 is ON ");
    }
    else if(digitalRead(D4)== HIGH)
    {
      lcd.print("LED 2 IS ON");
      }
   
    while(digitalRead(D8)== HIGH);
  }
   delay(1000);
    delay(8000);
  lcd.clear();

}
