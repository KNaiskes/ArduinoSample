#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
    lcd.init();
    lcd.init();
    lcd.backlight();
}

void loop() {

    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("LCD");
    lcd.setCursor(3,1);
    lcd.print("screen");
    delay(5000);
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("GoodBye!");
    delay(5000);
}
