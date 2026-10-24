# Kelson Rover — Wiring Documentation

## 1. System Overview

Kelson Rover uses an ESP32 microcontroller to control a four-wheel-drive chassis, read ultrasonic distance sensors, and operate a servo-mounted front sensor.

The rover supports Bluetooth-based remote control and autonomous obstacle avoidance.

## 2. ESP32 Pin Assignments

### Motor Driver Interface

| ESP32 GPIO | Signal |
| ---------- | ------ |
| GPIO 25    | IN1    |
| GPIO 26    | IN2    |
| GPIO 27    | IN3    |
| GPIO 14    | IN4    |

**Note:** These are the signal connections defined in the firmware. Confirm the motor driver's model and its input mapping before assembling the circuit.

### Front Ultrasonic Sensor

| ESP32 GPIO | Signal |
| ---------- | ------ |
| GPIO 32    | TRIG   |
| GPIO 33    | ECHO   |

The front sensor is mounted on a servo to scan different directions.

### Rear Ultrasonic Sensor

| ESP32 GPIO | Signal |
| ---------- | ------ |
| GPIO 16    | TRIG   |
| GPIO 17    | ECHO   |

The rear sensor checks for obstacles when the rover reverses.

### Servo Motor

| ESP32 GPIO | Signal       |
| ---------- | ------------ |
| GPIO 13    | Servo signal |

The firmware commands the servo to scan left, centre, and right.

## 3. Communication

The ESP32 initializes Bluetooth Serial with the device name:

`KELSON_BT`

The mobile control application sends single-character commands to the ESP32.

## 4. Power and Electrical Safety

* Use a suitable power supply for the motors and motor driver.
* Ensure the ESP32 receives the correct regulated supply voltage.
* Establish a common ground between the ESP32 and motor driver where required by the circuit design.
* **Important:** ESP32 GPIOs are not 5 V tolerant. Verify the ultrasonic sensor's ECHO output voltage and use an appropriate level shifter or voltage divider if it can output 5 V.
* Do not power motors directly from ESP32 GPIO pins.
* Verify the motor driver's current rating and the battery's voltage before operation.

## 5. Wiring Verification Status

The GPIO assignments in this document are taken from the current ESP32 firmware.

The following details still need physical verification:

* Exact motor driver model and terminal mapping
* Battery voltage and power distribution
* Ultrasonic sensor operating voltage and ECHO signal level
* Servo power arrangement
* Actual left/right motor orientation

This document should be updated if the physical wiring differs from the firmware configuration.
