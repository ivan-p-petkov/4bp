#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(2, INPUT);
}

void loop()
{
  int ok = digitalRead(2);
  int pressed = 0;
  
  if(ok == 0){
    lcd.setCursor(1, 0);
    lcd.print("Colour selected");
    delay(2000);
    pressed = 1;
  }
  
  if(pressed == 1){
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("New selection?");
    ok = digitalRead(2);
    if(ok == 0){
      lcd.setCursor(1, 0);
      lcd.print("Colour selected");
      delay(2000);
      pressed = 1;
    }
  }
}