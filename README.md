# seatAlignmentDetection

This project is designed to detect and monitor the arrangement status of chairs in a row using ultrasonic sensors and an Arduino-based IoT system. The detection mechanism relies on ultrasonic sound wave reflection, measuring the distance between the sensor and the nearest object (i.e., the chair). If a chair is detected within 12 cm, it is considered “Arranged”; otherwise, it is “Not Arranged.” The status of each chair is then updated in real-time to a Firebase Realtime Database, enabling remote monitoring.

## Key Components:
- Ultrasonic Sensors (2x): Continuously emit ultrasonic waves and measure the time it takes for the echo to return, determining object proximity.

- Arduino UNO: Microcontroller used to control sensor logic and process input.

- ESP8266-01 Wi-Fi Module: Enables internet connectivity and allows communication with the Firebase database.

- Firebase Realtime Database: Stores the chair arrangement status and makes the data accessible remotely.

## Technical Background:
The project uses ultrasonic wave-based ranging—a concept evolved from RADAR systems developed in the 1930s and used extensively in navigation and military applications.

The reflected sound wave is used to calculate distance, which is minimally affected by environmental factors like temperature and humidity, ensuring reliable detection.

## Working Principle:
- Distance Measurement: Ultrasonic sensors measure the distance from the sensor to the nearest chair.

- Threshold Logic: If the detected distance ≤ 12 cm, the system marks the chair as “Arranged”; otherwise, “Not Arranged.”

- Data Upload: The result is printed to the Arduino Serial Monitor and sent to the Firebase Realtime Database via ESP8266.

- Cloud Monitoring: A connected dashboard or database viewer can display real-time statuses of all connected chairs.

## Setup Instructions:
Software Configuration:
Install ESP8266 board in Arduino IDE:
URL: https://arduino.esp8266.com/stable/package_esp8266com_index.json

Add Required Libraries:

Firebase Arduino: GitHub – FirebaseExtended/firebase-arduino

ArduinoJSON (via Library Manager)

Create Firebase Realtime Database

Update security rules to public access (for testing purposes only).

Note the database URL and authentication key.

## Circuit diagram
<img width="879" height="685" alt="image" src="https://github.com/user-attachments/assets/07f6e56c-6f49-4a9b-87f9-5c685dd6009f" />

## Expected Output:
If object ≤ 12 cm:

Serial Monitor: "Arranged"

Firebase DB: "Arranged"

If object > 12 cm:

Serial Monitor: "Not Arranged"

Firebase DB: "Not Arranged"
