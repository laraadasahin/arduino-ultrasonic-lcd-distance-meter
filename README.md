# 📏 Embedded Distance Measurement System with LCD Display

This project demonstrates a real-time distance measurement system built using an **Arduino Uno**, an **HC-SR04 Ultrasonic Sensor**, and a **16x2 Liquid Crystal Display (LCD)**.

## 📌 Features
* **Real-time Measurement:** Calculates object distance using ultrasonic wave propagation times.
* **Dual Unit Support:** Displays values in both centimeters ($cm$) and inches ($inch$).
* **Visual Interface:** Embedded 16x2 LCD interface for live data monitoring.

## 🛠️ Hardware Components
* Arduino Uno Rev3
* HC-SR04 Ultrasonic Sensor Module
* 16x2 Character LCD Display
* Potentiometer (for LCD contrast adjustment)
* Breadboard & Jumper Wires

## ⚙️ How It Works
1. The **HC-SR04** sends a high-frequency sound pulse via the `Trigger` pin.
2. The pulse reflects back from the target object and is received by the `Echo` pin.
3. The duration of the echo signal is measured using Arduino's timing functions.
4. Distance is calculated using the speed of sound formula: 
   $$\text{Distance} = \frac{\text{Duration} \times \text{Speed of Sound}}{2}$$
5. The calculated values are rendered on the **16x2 LCD screen**.
