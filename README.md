# Temperature-Controlled Relay System with NodeMCU and DS18B20

This project demonstrates a temperature-controlled relay system using a NodeMCU, a DS18B20 temperature sensor, and a relay module. The system reads the temperature from the sensor, and when the temperature exceeds a set threshold (28°C in this case), it switches off the relay. The user can manually turn the relay back on using the serial monitor.

## Components Used

- NodeMCU ESP8266
- DS18B20 Temperature Sensor
- 4.7kΩ Resistor (for the DS18B20)
- Relay Module
- Jumper Wires
- Breadboard

## Pin Configuration

| NodeMCU Pin | Component           | Description               |
|-------------|---------------------|---------------------------|
| D2 (GPIO4)  | DS18B20 Data Pin     | Reads temperature data    |
| D1 (GPIO5)  | Relay Signal Pin     | Controls the relay        |

## Working of the Code

- The system reads the temperature using the DS18B20 sensor.
- If the temperature exceeds **28°C**, the relay turns off.
- If the temperature is below **28°C** and the relay is allowed, the relay remains on.
- If the relay is off due to high temperature, the user can manually turn it back on using the serial monitor by entering `1`.

## How to Use

1. **Setup Hardware:**
   - Connect the DS18B20 sensor's data pin to **D2 (GPIO4)** on the NodeMCU.
   - Connect the relay module's signal pin to **D1 (GPIO5)**.
   - Ensure you have the required connections for the DS18B20 sensor and the relay module.

2. **Install Libraries:**
   - Install the **OneWire** and **DallasTemperature** libraries in your Arduino IDE.
     - Go to **Sketch** > **Include Library** > **Manage Libraries** and search for these libraries.

3. **Upload the Code:**
   - Upload the code to the NodeMCU using the Arduino IDE.
   - Open the serial monitor at a baud rate of 9600.

4. **Testing:**
   - Once the temperature exceeds **28°C**, the relay will automatically turn off.
   - To manually turn the relay back on, type `1` in the serial monitor when prompted.

## Code Explanation

- `ONE_WIRE_BUS`: Pin for the DS18B20 sensor data.
- `RELAY_PIN`: Pin connected to the relay.
- The `DallasTemperature` library is used to read temperature values from the DS18B20.
- The relay is controlled based on the temperature value.
- A manual override option is provided via the serial monitor.

## Delay and Serial Monitor

- The system reads the temperature every 5 seconds (`delay(5000)`).
- The serial monitor is used to display the temperature and control messages.

## Future Improvements

- Add a web interface to control and monitor the relay status using the NodeMCU's Wi-Fi capabilities.
- Modify the system to allow for multiple temperature sensors.
- Add a hysteresis mechanism to avoid relay flickering at the threshold temperature.

## License

This project is open-source and available under the MIT License. Feel free to modify and improve the project.

