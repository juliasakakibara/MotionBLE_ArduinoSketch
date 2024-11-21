# **MotionBLE Arduino Sketch**

## **Description**

This repository contains an Arduino sketch for controlling the built-in LED and reading real-time accelerometer data from the Arduino Nano RP2040 Connect board.  
The sketch uses Bluetooth connectivity to enable remote control of the built-in LED and transmission of accelerometer readings to a companion iOS app.

The sketch was adapted from the original [iOSArduinoBLE Arduino Sketch](https://github.com/leonardocavagnis/iOSArduinoBLE_ArduinoSketch) to include accelerometer support and battery-powered operation.

---

## **Hardware Requirements**

- [Arduino Nano RP2040 Connect board](https://docs.arduino.cc/hardware/nano-rp2040-connect)

---

## **Usage**

1. Connect the Arduino Nano RP2040 Connect board to your computer.
2. Open the sketch in the [Arduino IDE](https://www.arduino.cc/en/software) (version 1.8.13 or later).
3. Select the appropriate board and port in the Arduino IDE.
4. Upload the sketch to the Arduino Nano RP2040 Connect board.
5. Install the companion mobile app from the [MotionBLE iOS App repository](https://github.com/juliasakakibara/MotionBLE_iOSApp).
6. Establish a Bluetooth connection between the Arduino Nano RP2040 Connect board and the mobile app.
7. Use the mobile app to control the built-in LED and view accelerometer readings in real-time.

---

## **Dependencies**

This sketch relies on the following libraries:

- [ArduinoBLE](https://www.arduino.cc/en/Reference/ArduinoBLE) for Bluetooth connectivity
- [Arduino_LSM6DSOX](https://www.arduino.cc/en/Reference/ArduinoLSM6DSOX) for accelerometer support

Please install these libraries through the Arduino Library Manager before uploading the sketch.

---

## **Modifications**

This project is based on the original work by [Leonardo Cavagnis](https://github.com/leonardocavagnis).  

Adaptations include:
- Real-time accelerometer data reading (X, Y, Z axes).
- Support for battery-powered operation.

---

## **Authors**

This project was originally developed by:
- [Leonardo Cavagnis](https://github.com/leonardocavagnis)

Adapted by:
- **Julia Sakakibara**
