
# Sanitary Pad Disposal Machine

This project automates the disposal of sanitary napkins through controlled incineration using a temperature-regulated system. The machine uses a **NodeMCU (ESP8266)** microcontroller, a **DS18B20 temperature sensor**, a **5V relay**, and a **nichrome wire** heating element. The system ensures efficient and safe disposal of sanitary pads, promoting hygiene and waste management.

## Table of Contents

- [Overview](#overview)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Setup Instructions](#setup-instructions)
- [Circuit Diagram](#circuit-diagram)
- [Code](#code)
- [Usage](#usage)

## Overview

The sanitary pad disposal machine incinerates used napkins by heating a nichrome wire, which is controlled by a relay and regulated by the temperature sensor. The entire system is controlled by the **NodeMCU (ESP8266)**, which ensures safe temperature regulation during the incineration process.

## Hardware Requirements

- **NodeMCU (ESP8266)**
- **DS18B20 Temperature Sensor**
- **5V Relay Module**
- **Nichrome Wire (Heating Element)**
- **Resistors (4.7kΩ pull-up resistor)**
- **Jumper Wires**
- **Reverse Bias Diode**
- **5V Power Supply/Adapter**
- **Micro USB Cable**

## Software Requirements

- **Arduino IDE** (with ESP8266 board support)
- **OneWire Library** (for temperature sensor communication)
- **DallasTemperature Library** (for DS18B20 temperature sensor)
- **CP210x Driver** (for NodeMCU communication)

## Setup Instructions

### 1. Install Software
1. Install the **Arduino IDE** from [here](https://www.arduino.cc/en/software).
2. Add the **ESP8266 board** to the Arduino IDE by navigating to `File > Preferences` and adding the ESP8266 board URL in the "Additional Boards Manager URLs" field.
3. Install the **OneWire** and **DallasTemperature** libraries via the Arduino Library Manager.
4. Install the **CP210x driver** to enable communication with the NodeMCU.

### 2. Wiring the Components
1. **NodeMCU and Temperature Sensor (DS18B20):**
   - Connect the **VCC** pin of the sensor to the **3.3V** pin of the NodeMCU.
   - Connect **GND** to **GND**.
   - Connect the **Data** pin of the sensor to the **D2** pin of the NodeMCU.
   - Use a **4.7kΩ pull-up resistor** between the **VCC** and **Data** pins.

2. **NodeMCU and Relay:**
   - Connect the **IN** pin of the relay to the **D1** pin of the NodeMCU.
   - Connect the relay’s **VCC** and **GND** pins to the NodeMCU’s **5V** and **GND** pins, respectively.

3. **Nichrome Wire (Heating Element) and Relay:**
   - Connect the **+ve terminal** of the power supply to the **nichrome wire**.
   - Connect the **-ve terminal** of the power supply to the **COM port** of the relay.
   - Use a **reverse-biased diode** in parallel with the nichrome wire for protection.

### 3. Upload the Code
1. Open the **Arduino IDE**.
2. Select **NodeMCU (ESP8266)** as the board and the correct **COM port**.
3. Upload the code from the `incinerator.ino` file (provided below).

## Circuit Diagram
Refer to SanitaryPadDisposalMachineReport.Pdf for the circuit and other diagrams

## Code
refer to the 

## Usage

1. Power the system by connecting the NodeMCU to your computer using the **Micro USB Cable**.
2. The system will automatically monitor the temperature inside the incinerator using the **DS18B20 temperature sensor**.
3. If the temperature exceeds the threshold (28°C), the relay will turn off the heating element (nichrome wire). If the temperature is below the threshold, the heating element remains on.
4. The user can manually restart the incinerator via the **Serial Monitor** by entering `1`.

