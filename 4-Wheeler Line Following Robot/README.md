# 🤖 4-Wheeler Line Following Robot using Arduino Uno

This project demonstrates how to build a **4-Wheeler Line Following Robot** using an **Arduino Uno**.  
The robot is capable of detecting and following a black line using **IR sensors**, while controlling four DC motors via an **L298N Motor Driver**.

This guide covers:
- Chassis assembly  
- Power system connections  
- Motor driver wiring  
- Arduino connections  
- IR sensor setup  

---

## 🔧 Components Required

| Component | Quantity |
|---------|----------|
| Gear Motors | 4 |
| 4-Wheel Robot Chassis | 1 |
| Arduino Uno | 1 |
| L298N Motor Driver Module | 1 |
| IR Sensors | 2 |
| Jumper Wires | Male–Male / Male–Female | 
| Double Battery Holder with Switch | 1 |
| 3.7v Lithium-ion Battery | 2 |
| USB Cable | 1 |

---

<p align="center">
  <img src="./Diagram.jpg" alt="Line Following Robot" width="800">
</p> 

---

## 📝 Project Description

A **Line Following Robot** is an autonomous robot that follows a predefined path, usually a black line on a white surface.  
This robot uses **two IR sensors** to detect the line and an **L298N motor driver** to control four DC motors for smooth movement.

---

## 🔋 Power System Connection

1. Take the **red (+)** and **black (-)** wires from the **Double Battery Holder**.
2. The **red wire** must be connected **through the switch**:
   - Connect the **red wire** from the battery holder to **one pin of the switch**.
   - Connect the **other pin of the switch** to the **positive (+) terminal of the DC Jack**.
3. Connect the **black wire (-)** directly to the **negative terminal of the DC Jack**.

⚠️ This ensures safe power control using the switch.

---

## ⚙️ Connecting Motors to L298N Motor Driver

1. Divide the **four DC motors into two pairs**.
2. Connect each motor pair to the motor output terminals of the L298N driver as shown in the motor driver diagram.
3. Identify the **positive (+)** and **negative (-)** terminals of each motor pair.
4. Ensure correct polarity when connecting the motors to avoid reverse rotation issues.

---

## 🔌 Connecting L298N Motor Driver to Arduino Uno

1. Remove the jumper caps from **ENA** and **ENB** pins on the L298N module.
2. Make the following connections:

| L298N Pin | Arduino Pin |
|----------|-------------|
| ENA | Digital Pin 10 |
| IN1 | Digital Pin 9 |
| IN2 | Digital Pin 8 |
| IN3 | Digital Pin 7 |
| IN4 | Digital Pin 6 |
| ENB | Digital Pin 5 |

🎯 These pins allow speed and direction control using PWM signals.

---

## 🔋 Powering the L298N and Arduino

1. Take the **positive (+)** and **negative (-)** wires from the battery holder.
2. Connect:
   - **Positive (+)** → L298N **12V** pin  
   - **Negative (-)** → L298N **GND** pin
3. From the same **12V** and **GND** points on the motor driver:
   - Use two **male jumper wires**.
4. Connect:
   - **12V (+)** → Arduino **VIN** pin  
   - **GND (-)** → Arduino **GND** pin  

⚡ This allows both the motor driver and Arduino to share the same power source.

---

## 📡 Connecting IR Sensors to Arduino

### IR Sensor Connections

| IR Sensor Pin | Arduino Pin |
|--------------|-------------|
| VCC | 5V |
| GND | GND |
| OUT (Right Sensor) | A0 |
| OUT (Left Sensor) | A1 |

📌 Place the sensors close to the ground for accurate line detection.

---

## ✅ Final Notes

- Make sure all **GND connections are common**.
- Double-check motor polarity if the robot moves incorrectly.
- Adjust IR sensor sensitivity using onboard potentiometers.
- Upload your Arduino code using the **USB cable**.