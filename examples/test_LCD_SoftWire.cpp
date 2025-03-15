#if 1
#include <Arduino.h>
#include <SoftWire.h>
#include <LiquidCrystal_PCF8574_SoftWire.h>

//TwoWire wire = TwoWire();

//SoftWire wire(PB9, PB8);
SoftWire   wire(PA12, PA11);

LiquidCrystal_PCF8574_SoftWire lcd(0x27); // set the LCD address to 0x27

void setup() {
    Serial.begin(115200);
    Serial.println("LCD SoftWire");
    wire.begin(); 
    wire.setClock(100000); // I2C speed 100kHz 
    lcd.begin(16, 2,wire); // initialize the lcd for a 16 chars and 2 line
    lcd.setBacklight(255); 
}

void loop() {
    lcd.setBacklight(255);  
    lcd.home(); 
    lcd.clear(); 
    lcd.print("GSOG (:-"); 
    delay(1000); 
    lcd.clear(); 
    lcd.setCursor(0, 0); 
    lcd.print("*** first line."); 
    lcd.setCursor(0, 1); 
    lcd.print("*** second line."); 
    delay(1000); 
    lcd.scrollDisplayLeft(); 
    lcd.scrollDisplayLeft(); 
    lcd.scrollDisplayLeft(); 
    delay(1000);
    lcd.setBacklight(0); 
    delay(1000);
    Serial.print("x");    
}
#endif