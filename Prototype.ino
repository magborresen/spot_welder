#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2,  1,  0,  4,  5,  6,  7,  3,  POSITIVE);
int potPin = A0;
int val = 0;
const int LED = 13;
const int knap = 12;
  
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);                    // Define the display size charecterwise (width, height)
  lcd.clear();                        // Clear LCD
  lcd.setCursor(0,0);                 // Set start point on LCD
  lcd.print("Weld-time: ");           // Print first, then the screen won't flicker at each cycle
  pinMode(LED, OUTPUT);
  pinMode(knap, INPUT_PULLUP);
  digitalWrite(LED, LOW);
}

void loop() 
{
   val = analogRead(potPin)/5;
   if(val < 1)                       // Make sure val can't < 1
   {
     val = 1; 
   }
   if(val > 200)
   {
     val = 200;
   }
   lcd.setCursor(11,0);               // Posistion on screen for val to be
   lcd.print(val);
   lcd.print("ms  ");
   if(digitalRead(knap) == HIGH)
   {
     lcd.setCursor(0,1);
     lcd.print("Welding.");
     delay(667);
     lcd.setCursor(0,1);
     lcd.print("Welding..");
     delay(667);
     lcd.setCursor(0,1);
     lcd.print("Welding...");
     delay(667);
     digitalWrite(LED, HIGH);
     delay(val);
     digitalWrite(LED, LOW);
   }
   else if(digitalRead(knap) == LOW)
   {
     lcd.setCursor(0,1);
     lcd.print("Standby   ");
     delay(50);
   }
}
