# Kelson Rover — Hardware Components

## Overview

Kelson Rover is a four-wheel-drive mobile robot built around an ESP32 microcontroller. Its hardware combines motor control, ultrasonic distance sensing, servo-based scanning, and Bluetooth communication.

## Component Inventory

| Component                  | Function                                                                                      |
| -------------------------- | --------------------------------------------------------------------------------------------- |
| ESP32 development board    | Executes the rover firmware and manages Bluetooth communication, sensors, and motor commands. |
| Four-wheel-drive chassis   | Provides the rover's mobile platform.                                                         |
| DC gear motors             | Drive the rover's wheels.                                                                     |
| Motor driver               | Interfaces the controller with the drive motors. Exact model to be confirmed.                 |
| Front ultrasonic sensor    | Measures distance ahead of the rover.                                                         |
| Servo motor                | Rotates the front ultrasonic sensor to scan different directions.                             |
| Rear ultrasonic sensor     | Measures distance behind the rover.                                                           |
| Battery and power system   | Supplies power to the electronics and drive system. Exact ratings to be confirmed.            |
| Android mobile application | Provides the user interface for rover control.                                                |
| MIT App Inventor           | Platform used to develop the mobile application.                                              |

## Front Sensing System

The front ultrasonic sensor is mounted on a servo motor. The firmware commands the servo to several angles and takes distance measurements to evaluate the space around the rover.

## Rear Sensing System

A second ultrasonic sensor is stationary and faces the rear. The firmware uses its distance measurement when deciding whether reverse movement is appropriate.

## Motor Control

The ESP32 generates digital control signals for the motor driver through four output pins:

* GPIO 25
* GPIO 26
* GPIO 27
* GPIO 14

The exact correspondence between these pins and the individual motor-driver inputs must be verified against the physical wiring.

## Communication

The firmware initializes Bluetooth with the device name `KELSON_BT`. The mobile application communicates with the rover using single-character commands.

## Verification Status

This document describes the architecture represented in the firmware. Component models, electrical ratings, power connections, and physical wiring should be verified before hardware modifications or reproduction.
