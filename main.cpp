
#include <LiquidCrystal_I2C.h>

// C++ code
int triggerpin = 9 ;
int echopin = 10;
long duration;
float distance;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  Serial.begin(9600);
  pinMode(triggerpin, OUTPUT);
  pinMode(echopin,INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Distance:");
  
}

void loop()
{
  digitalWrite(triggerpin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin, LOW);
  
  // calculate distance
  duration = pulseIn(echopin,HIGH);
  distance = duration * 0.034 / 2;
  
  //lcd displays
  lcd.setCursor(9,0);
  lcd.print(distance);
  if (distance <= 100){
    lcd.setCursor(0,1);
    lcd.print("Hello");
  }else{
    lcd.setCursor(0,1);
    lcd.print("              ");
  }
  
}