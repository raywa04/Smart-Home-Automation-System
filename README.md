
# Smart Home Automation System

This project is a simple smart home automation system using an ESP32 microcontroller. It allows users to control an LED via a web interface, with communication handled through MQTT.

## Components

- ESP32 Microcontroller
- LED
- Wi-Fi Network
- MQTT Broker (e.g., Mosquitto)
- Flask Web Server

## Setup

1. **ESP32:**
   - Connect the LED to GPIO 2.
   - Update `WiFiSetup.cpp` with your Wi-Fi credentials.
   - Update `MQTTSetup.cpp` with your MQTT broker address.
   - Upload the code to the ESP32.

2. **Web Interface:**
   - Host the `index.html` and `style.css` files on a web server.

3. **Backend Server:**
   - Install Flask and Paho MQTT client: `pip install flask paho-mqtt`
   - Run the Flask server: `python server.py`

4. **MQTT Broker:**
   - Install and run an MQTT broker like Mosquitto.

## Usage

- Access the web interface and use the buttons to control the LED.
- The web interface sends requests to the Flask server, which then publishes messages to the MQTT broker.
- The ESP32 subscribes to the MQTT topic and controls the LED based on the received messages.
