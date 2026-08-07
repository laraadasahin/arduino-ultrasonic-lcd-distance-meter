/*
 * Embedded Systems - I2C Ultrasonic Distance Meter with LCD
 * Author: Lara Ada Şahin
 * Description: Real-time distance measurement system using HC-SR04, 
 * Arduino Uno, and 16x2 I2C LCD Display.
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C LCD Ekran Tanımlaması (Adres: 0x27, 16 sütun, 2 satır)

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Sensör Pin Bağlantıları 
const int trigPin = A0;
const int echoPin = A1;

void setup() {
  // LCD Ekranı Başlatma ve Arka Işığı Açma
  lcd.init();
  lcd.backlight();
  
  // Sensör Pin Modları
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Seri Haberleşmeyi Başlatma (Serial Monitor için)
  Serial.begin(9600);
  
  // Karşılama Ekranı 
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

  // Ultrasonik Sensör Tetikleme (Pulse Gönderimi)
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Ses Dalgasının Dönüş Süresini Ölçme
  duration = pulseIn(echoPin, HIGH);

  // Mesafe Hesabı (cm ve inç)
  distanceCm = (duration / 2) / 29.1;
  distanceInch = distanceCm * 0.393701;

  // Serial Monitor Çıktısı (Bilgisayardan Kontrol İçin)
  Serial.print("Mesafe: ");
  Serial.print(distanceCm);
  Serial.print(" cm | ");
  Serial.print(distanceInch);
  Serial.println(" inch");

  // LCD Ekran Güncellemesi
  lcd.clear();
  
  // 1. Satır: Centimeter
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distanceCm);
  lcd.print(" cm");

  // 2. Satır: Inch
  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(distanceInch);
  lcd.print(" inch");

  // Ekranda Titremeyi Önlemek İçin 300ms Bekleme
  delay(300);
}
