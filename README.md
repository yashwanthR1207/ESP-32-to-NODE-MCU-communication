# ESP32 to NodeMCU ESP-NOW Communication

This repository contains the code to transmit data from an ESP32 to a NodeMCU (ESP8266) using the ESP-NOW protocol.

## Prerequisites
- ESP32 Development Board
- NodeMCU (ESP8266) Development Board
- Arduino IDE with ESP32 and ESP8266 boards installed

## Configuration
Before uploading the code, ensure you have the correct MAC address of the receiver (NodeMCU). Update the `receiverMAC` array in the code with the MAC address of your specific receiver board.

## Usage
1. Open the .ino file in the Arduino IDE.
2. Select your ESP32 board and the correct COM port.
3. Upload the code to the ESP32.
4. Open the Serial Monitor at 115200 baud rate to verify the setup and check transmission status.
