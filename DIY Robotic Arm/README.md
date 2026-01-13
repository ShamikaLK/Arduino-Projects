# 🤖 DIY Robotic Arm  
### Interactive Robotic Arm using Arduino UNO, Servo Motors & Joystick

Precise object manipulation can be challenging without an efficient control system.  
**DIY AutoArm** is a joystick-controlled robotic arm that provides a smooth and intuitive way to control movement using servo motors. This project is ideal for beginners and hobbyists who want to learn the fundamentals of **automation, robotics, and Arduino-based control systems**.

---

## 🔧 Features
- 🎮 Joystick-based real-time control  
- ⚙️ Smooth movement using servo motors  
- 🔋 Portable battery-powered system  
- 🧠 Great learning project for robotics & automation  

---

## 🧩 Components Required

| Component | Quantity |
|---------|----------|
| Arduino UNO Board | 1 | 
| Servo Motors | 2 | 
| Joystick Module | 1 | 
| Ice Cream Sticks (for arm structure)  
| Jumper Wires  
| Double Battery Holder with DC Jack & Switch | 1 | 
| 3.7V Rechargeable Batteries | 2 | 

---

## 🖼️ Project Diagram

<p align="center">
  <img src="./Diagram.jpg" alt="DIY Robotic Arm" width="800">
</p> 

---

## 📚 Required Arduino Libraries (Very Important)

Before uploading the code, **make sure the following libraries are installed in the Arduino IDE**:

- **Servo Motor Library**
- **Joystick Library**

### 🔍 How to Check if Libraries Are Installed
1. Open **Arduino IDE**
2. Go to **File → Examples**
3. Scroll down and check if **Examples from Custom Libraries** is visible  
   - If visible ✅ libraries are installed correctly

### 📥 How to Install / Update Libraries
1. Open **Arduino IDE**
2. Press **Ctrl + Shift + I** to open **Library Manager**
3. In the **Search Box**, type:
   - `Servo`
   - `Joystick`
4. If not installed → click **Install**
5. If already installed → check for **Updates** and update if available

⚠️ **If errors appear after installation**, close the Arduino IDE and reopen it, then try again.

---

## 🔌 Power System Wiring Instructions

Follow these steps carefully to avoid power issues:

- The **Double Battery Holder** has:
  - 🔴 Red Wire (Positive)
  - ⚫ Black Wire (Negative)

### 🔋 Connections
1. Connect the **Black (Negative) wire** directly to the **DC Jack negative terminal**
2. Connect the **Red (Positive) wire** to **one pin of the switch**
3. Connect the **other pin of the switch** to the **Positive terminal of the DC Jack**

✅ This setup allows safe power control using the switch.

---

## 🛠️ Assembly Notes
- Use **ice cream sticks** to build the robotic arm structure
- Secure servo motors firmly to avoid vibration
- Make sure joystick connections match the Arduino pin configuration in the code

---

## 🚀 Getting Started
1. Install required libraries
2. Assemble the robotic arm
3. Connect components according to the circuit
4. Upload the Arduino sketch
5. Power ON and control the arm using the joystick 🎮

---

## 📌 Learning Outcomes
- Arduino programming
- Servo motor control
- Joystick interfacing
- Basic robotic arm mechanics
- Power management with batteries