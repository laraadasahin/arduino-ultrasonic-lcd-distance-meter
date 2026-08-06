/*
 * Embedded Systems - Ultrasonic Distance Meter with LCD
 * Author: Lara Ada Şahin
 * Description: Distance measurement system using HC-SR04 and 16x2 LCD.
 * Includes distance calculation in both cm and inches.
 */

#include <LiquidCrystal.h>

// LCD Pin konfigürasyonu (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(10, 9, 5, 4, 3, 2);

// Sensör Pinleri
const int trigPin = 11;
const int echoPin = 12;
const int lcdBacklightPin = 6; // LCD Arka Işık (PWM)

void setup() {
  // LCD Arka Işık parlaklığı
  analogWrite(lcdBacklightPin, 100);
  
  // LCD ekranı başlat (16 sütun, 2 satır)
  lcd.begin(16, 2);
  
  // Sensör pin modları
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Seri haberleşmeyi başlat (Hata ayıklama için)
  Serial.begin(9600);
  
  // Başlangıç ekranı (Profesyonel dokunuş)
  lcd.setCursor(0, 0);
  lcd.print(" Distance Meter ");
  lcd.setCursor(0, 1);
  lcd.print(" Initializing... ");
  delay(1500);
  lcd.clear();
}

void loop() {
  long duration;
  int distanceCm;
  int distanceInch;

  // Ultrasonik dalga gönderimi (Trig pini)
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Yanıt süresini ölç (Echo pini)
  duration = pulseIn(echoPin, HIGH);

  // Mesafe Hesaplamaları (cm ve inç)
  distanceCm = (duration / 2) / 29.1;
  distanceInch = distanceCm * 0.393701; // cm'yi inç birimine dönüştürme

  // Serial Monitor Çıktısı
  Serial.print("Mesafe: ");
  Serial.print(distanceCm);
  Serial.print(" cm | ");
  Serial.print(distanceInch);
  Serial.println(" inç");

  // LCD Ekran Güncellemesi
  lcd.clear();
  
  // Satır 0: Santimetre gösterimi
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distanceCm);
  lcd.print(" cm");

  // Satır 1: İnç gösterimi
  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(distanceInch);
  lcd.print(" inch");

  // Ekranın çok hızlı yanıp sönmesini önlemek için yenileme süresi
  delay(300);
}
