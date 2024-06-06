from flask import Flask
import paho.mqtt.client as mqtt

app = Flask(__name__)
mqtt_client = mqtt.Client()

mqtt_client.connect("your_MQTT_server_address", 1883, 60)

@app.route('/led/<state>')
def led_control(state):
    if state == "on":
        mqtt_client.publish("home/led", "ON")
    elif state == "off":
        mqtt_client.publish("home/led", "OFF")
    return "OK"

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=80)
