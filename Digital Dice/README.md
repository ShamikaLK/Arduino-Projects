# 🎲 Arduino Digital Dice Project

Imagine having a dice that’s always ready to roll at the press of a button, complete with sound effects to make every roll exciting! This project shows how to build a **Digital Dice** using an **Arduino UNO**, a **7-Segment Display**, a **Push Button**, and a **Buzzer**. Perfect for beginners and fun Arduino demos 🚀

---

## 🔧 Components Required

| Component                                            | Quantity |
| ---------------------------------------------------- | -------- |
| Arduino UNO                                          | 1        |
| Breadboard                                           | 1        |
| 7-Segment Display (Common Anode)                     | 1        |
| Resistor (220 ohm)                                   | 1        |
| Buzzer                                               | 1        |
| Push Button                                          | 1        |
| USB Cable                                            | 1        |
| Double Battery Holder with DC Jack and Switch Button | 1        |
| 3.7V Lithium Battery                                 | 2        |
| Jumper Wires                                         | As required       |

> ⚠️ Tip: Always double-check jumper wire types before purchasing.

---

## 🖼️ Project Diagram

<p align="center">
  <img src="./Diagram.png" alt="Digital Dice" width="800">
</p> 

----

## 📝 Project Description

This digital dice generates a random number between **1 and 6** whenever the push button is pressed. The number is displayed on a **7-segment display**, and a **buzzer sound** adds excitement to each roll. Power can be supplied via USB or an external battery using a DC jack and switch system.

---

## 🔌 Circuit Connection Guide

Follow the steps carefully to build the circuit correctly:

1. Connect the **"ca" pin** of the 7-Segment Display to a **220 ohm resistor**. [view](./7-Segment%20Display%20pinout.png)
2. Connect the other end of the resistor to the **positive (+) rail** of the breadboard.
3. Connect the **"g" pin** of the 7-Segment Display to **Arduino digital pin 5**.
4. Connect the **"f" pin** to **Arduino digital pin 6**.
5. Connect the **"a" pin** to **Arduino digital pin 7**.
6. Connect the **"b" pin** to **Arduino digital pin 8**.
7. Connect the **"e" pin** to **Arduino digital pin 4**.
8. Connect the **"d" pin** to **Arduino digital pin 3**.
9. Connect the **"c" pin** to **Arduino digital pin 2**.
10. Mount the **Push Button** on the breadboard as shown in the diagram. [view](#️-project-diagram)
11. Connect **terminal 1** of the Push Button to the **negative (-) rail** of the breadboard.
12. Connect **terminal 2** of the Push Button to **Arduino analog pin A0**.
13. Connect the **positive (+) pin** of the Buzzer to **Arduino digital pin 10**.
14. Connect the **negative (-) pin** of the Buzzer to the **negative (-) rail** of the breadboard.
15. Connect **Arduino 5V pin** to the **positive (+) rail** of the breadboard.
16. Connect **Arduino GND pin** to the **negative (-) rail** of the breadboard.

---

## 🔋 Power System Connection

* The **Double Battery Holder** has **red (positive)** and **black (negative)** wires.
* Connect these wires to the **DC Jack**.
* While connecting:

  * Attach the **red wire** from the battery holder to **one pin of the switch**.
  * Connect the **other pin of the switch** to the **positive wire of the DC Jack**.
  * The **black wire** connects directly to the **negative terminal** of the DC Jack.

This allows you to safely turn the power ON/OFF using the switch 🔌

---

## ✅ Notes

* Make sure the 7-segment display is **Common Anode**.
* Ensure correct polarity when connecting the buzzer and power supply.
* Upload the Arduino code only after verifying all connections.

---

## 🎉 Result

Press the button ➡️ The dice rolls ➡️ A random number (1–6) appears ➡️ Buzzer beeps 🎶