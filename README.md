
# 🔐 Smart Home Control Panel using Arduino UNO

A simple yet functional **home automation prototype** built with Arduino, simulating a secure entry system, temperature monitoring, fan control, and alert system — all in one project!

> 🚀 Built and simulated using **Tinkercad**  
> 🎓 Designed by: Ciradeep (ECE Student, Embedded Systems Enthusiast)

---

## 📌 Features

- 🔑 **Password-Protected Entry**
  - Serial Monitor acts as a keypad input for secure access.
  
- 🌀 **Fan Speed Control**
  - Controlled using a potentiometer; speed dynamically mapped via PWM.
  
- 🌡️ **Temperature Sensor Integration**
  - Analog temperature sensor (LM35) monitors room conditions in real-time.
  
- 🔴 🟢 🔵 **LED Status Indicators**
  - Blue: Cool (T < 25°C)  
  - Green: Normal (25°C ≤ T ≤ 35°C)  
  - Red: Overheat (T > 35°C) with buzzer alert
  
- 🚨 **Buzzer Alert**
  - Alerts the user if temperature exceeds safe threshold or wrong password is entered.

---

## 🖥️ Simulation

- **Platform**: [Tinkercad by Autodesk](https://www.tinkercad.com/)
- **Hardware Used (Simulated)**:
  - Arduino UNO
  - Potentiometer (Fan speed control)
  - LM35 Temperature Sensor
  - RGB LEDs (Red, Green, Blue)
  - Buzzer
  - Serial Monitor (for password entry)

---

## 🔄 Demo Cases

1. ✅ **Correct Password + Normal Temp**  
   → Green LED, Fan ON

2. ❌ **Wrong Password Attempt**  
   → Red LED + Buzzer alert, No fan access

3. ⚠️ **Correct Password + Overheat (T > 35°C)**  
   → Red LED + Buzzer, Fan Off

---

## 🧠 Logic Overview

```c
if (user == pass) {
  // Access Granted
  if (temp < 25) → Blue LED
  else if (temp ≤ 35) → Green LED
  else → Red LED + Buzzer
} else {
  // Access Denied
  Red LED + Buzzer
}
