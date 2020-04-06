#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

const int trigpin = 11;
const int echopin = 10;

long duration;
int distance;

void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);

  duration = pulseIn(echopin,HIGH);
  distance = duration*0.034/2;

  Serial.print("distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("distance ");
  lcd.print(distance);
  lcd.print(" cm");
  delay(100);
  

}
