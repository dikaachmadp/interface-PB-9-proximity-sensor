#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int proxsensor = A2;
const int LED = 7;
const int BUZZ = 8;
int pinbatas = A0;
int proxval = 0;

void setup() {
  pinMode(proxsensor, INPUT);

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("System Aktif !");
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("Dika Achmad P");
  lcd.setCursor(3,1);
  lcd.print("6702191072");
  delay(1000);
  pinMode(pinbatas, INPUT); 
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  
  if (digitalRead(proxsensor) == LOW) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ada Halangan!");
    digitalWrite(LED, HIGH);
    proxval = analogRead(proxsensor);
    lcd.setCursor(0,1);
    lcd.print(proxval);
    delay(1000);
 } 
 
  if (digitalRead(proxsensor) == HIGH) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Clear!");
    digitalWrite(LED, LOW);
    proxval = analogRead(proxsensor);
    lcd.setCursor(0,1);
    lcd.print(proxval);
    delay(1000);
 } 
  
}
