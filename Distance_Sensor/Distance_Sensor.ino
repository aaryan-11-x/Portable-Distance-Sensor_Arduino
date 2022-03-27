#include <LiquidCrystal.h>
int rs = 7, re = 8, dp4 = 9, dp5 = 10, dp6 = 11, dp7 = 12;
int j = 0, push = 4;
int trig = 3, echo = 2, d = 10, cond2 = 0;
int pingTime;
float v = 0, buck = 0;
int dist = 0;
LiquidCrystal lcd(rs, re, dp4, dp5, dp6, dp7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);   // 16 Columns, 2 Rows
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(push, INPUT);
  digitalWrite(push, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int r = digitalRead(push);
  Serial.println(r);
  lcd.setCursor(0,0);
  if(r == 1 && cond2 == 0){
  lcd.print("Press The Button");
  delay(100);
  lcd.clear();
  }
  if (cond2 == 1) {
    lcd.setCursor(0, 0);
    digitalWrite(trig, LOW);
    delayMicroseconds(d);
    digitalWrite(trig, HIGH);
    delayMicroseconds(d);
    digitalWrite(trig, LOW);
    pingTime = pulseIn(echo, HIGH);
    dist = (pingTime/2)/29.1;
    Serial.println(String(dist) + "cm");
    lcd.print("Distance = "+String(dist) + " cm");
    delay(300);
    lcd.clear();
  }
  if (r == 0 && cond2 == 0) {
    cond2 = 1;
  }
}
