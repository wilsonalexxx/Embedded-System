// C++ code
//
#include <LiquidCrystal.h>
#include <DHT.h> 

LiquidCrystal lcd(13, 12, 7, 6, 5, 4);
const int LampuBiru = 10, LampuMerah = 9, ultraviolet = 2;
int relay = 3;
DHT dht(11, DHT11);


void setup(){
  lcd.begin(16, 2);
  // lcd.print("Temperature:");
  // Serial.begin(9600);
  pinMode(LampuBiru, OUTPUT);
  pinMode(LampuMerah, OUTPUT);
  pinMode(ultraviolet, OUTPUT);
  pinMode(relay, OUTPUT);
  dht.begin();
}

void loop(){
  lcd.setCursor(0, 1);
  lcd.print("Temperature:");
  float suhu = dht.readTemperature();
  
  
  if (suhu > 28 && suhu <33){
    digitalWrite(relay, HIGH);
    digitalWrite(LampuBiru, HIGH);
    digitalWrite(ultraviolet, HIGH);
    digitalWrite(LampuMerah, LOW);
  } else {
    digitalWrite(relay, LOW);
    digitalWrite(LampuMerah, HIGH);
    digitalWrite(ultraviolet, LOW);
    digitalWrite(LampuBiru, LOW);
  }
  lcd.setCursor(10, 1);
  lcd.print(suhu);
  lcd.print(" C");
  // digitalWrite(LampuBiru, HIGH);
  // digitalWrite(ultraviolet, HIGH);
  // digitalWrite(LampuMerah, HIGH);
  // Serial.print("\n");
  // Serial.print(suhu);
  delay(1000);
}