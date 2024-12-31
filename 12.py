https://github.com/ahmedjjameel/MQTT-Protocol-using-Python
pip install paho-mqtt

mqtt_publisher.py
.............................................................
import paho.mqtt.client as mqtt
import time
import random

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT broker")
    else:
        print("Failed to connect, return code %d\n", rc)

client = mqtt.Client()
client.on_connect = on_connect
client.connect("test.mosquitto.org", 1883, 60)
client.loop_start()

while True:
    temperature = round(random.uniform(20.0, 35.0), 2)
    humidity = round(random.uniform(30.0, 80.0), 2)
    
    message = f"Temperature: {temperature}°C, Humidity: {humidity}%"
    client.publish("topic/test", message)
    print(f"Message published: {message}")
    
    time.sleep(5)


mqtt_subscriber.py
..........................................................
import paho.mqtt.client as mqtt

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected to MQTT broker")
        client.subscribe("topic/test")
    else:
        print("Failed to connect, return code %d\n", rc)

def on_message(client, userdata, msg):
    print("Received message: ", str(msg.payload.decode("utf-8")))

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("test.mosquitto.org", 1883, 60)
client.loop_forever()
