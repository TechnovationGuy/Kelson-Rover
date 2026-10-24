# Kelson-Rover
A smart 4WD rover featuring Bluetooth RC control, autonomous obstacle avoidance, voice commands, and interactive behaviors.
# 🤖 KELSON ROVER

### A Smart 4WD Rover with RC, Autonomous & Voice-Control Modes

> A robotics project exploring embedded systems, mobile robot control, obstacle avoidance, and human–robot interaction.

Kelson Rover is a four-wheel-drive robotic platform built around an ESP32-based control system. It combines mobile-app control, obstacle-aware driving, autonomous navigation experiments, and voice-command interaction.

What makes Kelson different is its personality: when it detects an obstacle during RC or voice-controlled operation, it can perform a playful sensor-sweeping gesture as if responding, **"Nooo!"**

---

## 🚀 Features

* **RC Mode:** Drive the rover through a custom mobile interface.
* **Auto Mode:** Navigate using ultrasonic distance measurements and obstacle-avoidance logic.
* **Voice Mode:** Control movement through supported voice commands.
* **Bluetooth Communication:** Connect the mobile application to the rover.
* **Front Obstacle Detection:** Use a servo-mounted ultrasonic sensor to inspect the path ahead.
* **Rear Obstacle Detection:** Use a second, stationary ultrasonic sensor for rear obstacle awareness, if enabled in the corresponding firmware.
* **Interactive Behaviour:** Trigger a playful front-sensor sweep in response to an obstacle or supported voice interaction.

*Implementation note: Features are documented at the system level. Their exact firmware implementation and availability in each mode will be verified against the source code.*

## 🧠 The Three Control Modes

| Mode       | Purpose                                                                       |
| ---------- | ----------------------------------------------------------------------------- |
| RC Mode    | Manual driving through the mobile application, with obstacle-aware behaviour. |
| Auto Mode  | Autonomous movement using ultrasonic sensing and obstacle-avoidance logic.    |
| Voice Mode | Movement and supported interactions through voice commands.                   |

### The "Nooo!" Gesture

Kelson is designed to do more than simply stop when an obstacle appears.

When the relevant obstacle-response logic is triggered, the front ultrasonic sensor can sweep through its viewing range. This creates a playful gesture that gives the rover a distinctive personality.

The exact trigger conditions and servo movements will be documented alongside the verified firmware.

## 🛠️ Hardware

The project has been associated with the following components:

* ESP32 development board
* Four-wheel-drive chassis
* DC gear motors
* Motor driver
* Front ultrasonic distance sensor
* Servo motor for front sensor scanning
* Rear ultrasonic distance sensor
* Battery and power-distribution system

The exact motor-driver model, pin assignments, power arrangement, and sensor connections will be documented in the hardware section after verification.

## 💻 Software & Tools

* Arduino IDE / Arduino-compatible firmware
* Embedded C/C++
* MIT App Inventor
* Bluetooth-based mobile control
* Ultrasonic sensing
* Servo control
* Obstacle-avoidance algorithms

## 🏗️ System Architecture

**Mobile application → Bluetooth communication → Rover controller → Motor driver → Drive motors**

The controller also processes distance measurements from the ultrasonic sensors and commands the front servo when scanning is required.

The final architecture will be updated to reflect the verified firmware and the way the ESP32, sensors, and motor driver are connected.

## 📂 Repository Structure

```text
kelson-rover/
├── README.md
├── firmware/
│   ├── rc-mode/
│   ├── auto-mode/
│   └── voice-mode/
├── hardware/
│   ├── wiring-diagram/
│   └── components.md
├── app/
│   └── mit-app-inventor/
├── docs/
│   ├── system-architecture.md
│   └── testing.md
└── media/
    ├── images/
    └── videos/
```

*This is the planned structure. Directories will be added as the corresponding files become available.*

## 🔬 Engineering Challenges

Areas of interest in this project include:

* Coordinating mobile commands with low-level motor control.
* Detecting obstacles without unnecessarily interrupting manual driving.
* Comparing ultrasonic distance measurements to select a clear direction.
* Integrating voice interaction with movement and safety responses.
* Combining functional robotics with expressive human–robot interaction.

## 🔭 Future Improvements

* More robust obstacle detection and reverse-motion safety.
* Improved motor-speed calibration and turning accuracy.
* Better separation of control, sensing, and communication logic.
* Documented testing across different surfaces and obstacles.
* Additional autonomy experiments and improved voice interactions.

## 👨‍💻 Project Information

**Project:** Kelson Rover
**Category:** Robotics · Embedded Systems · Mobile Robots
**Controller:** ESP32-based system
**Mobile Application:** MIT App Inventor
**Status:** Development and documentation

This repository documents the engineering work, implementation, testing, and future development of Kelson Rover.

---

*Built with curiosity, electronics, code, and a little robotic personality.* 🤖
