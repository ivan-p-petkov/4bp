#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <LiquidCrystal_I2C.h>

#define TCS34725_INTEGRATIONTIME TCS34725_INTEGRATIONTIME_50MS
#define TCS34725_GAIN TCS34725_GAIN_1X

#define BUTTON_PIN 2 // Change this to the pin your button is connected to

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME, TCS34725_GAIN);
LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD address: 0x27. Adjust this according to your setup

bool buttonState = false;
bool prevButtonState = false;

void setup() {
  Serial.begin(9600);
  
  Wire.begin(); // Initialize I2C bus
  
  if (!tcs.begin()) {
    Serial.println("Error initializing TCS34725 sensor!");
    while (1);
  }

  pinMode(BUTTON_PIN, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor

  lcd.init(); // Initialize the LCD with I2C module
  lcd.backlight(); // Turn on backlight
  lcd.begin(16, 2); // Initialize LCD columns and rows
  
  Serial.println("Sensor Ready");
  lcd.print("Sensor");
  lcd.setCursor(0, 1);
  lcd.print("Ready");
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);

  // Check if button state has changed
  if (buttonState != prevButtonState) {
    delay(50); // Debouncing delay
    if (buttonState == LOW) { // Button pressed
      uint16_t clear, red, green, blue;
      tcs.getRawData(&red, &green, &blue, &clear);
      
      // Display color readings on LCD
      lcd.clear();
      lcd.print("R:"); lcd.print(red*2); lcd.print("ml");
      lcd.setCursor(9, 0);
      lcd.print("G:"); lcd.print(green*2); lcd.print("ml");
      lcd.setCursor(0, 1);
      lcd.print("B:"); lcd.print(blue*2); lcd.print("ml");
    }
    prevButtonState = buttonState;
  }
}
