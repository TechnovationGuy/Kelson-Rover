//looking for this
#include "BluetoothSerial.h"
#include <ESP32Servo.h>

BluetoothSerial SerialBT;
Servo headServo;

// =======================
// MOTOR PINS
// =======================
#define IN1 25
#define IN2 26
#define IN3 27
#define IN4 14

// =======================
// FRONT SENSOR + SERVO
// =======================
#define SERVO_PIN 13
#define TRIG_FRONT 32
#define ECHO_FRONT 33

// =======================
// BACK SENSOR
// =======================
#define TRIG_BACK 16
#define ECHO_BACK 17

bool autoMode = false;

// =======================
// SETUP
// =======================
void setup() {
  SerialBT.begin("KELSON_BT");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG_FRONT, OUTPUT);
  pinMode(ECHO_FRONT, INPUT);

  pinMode(TRIG_BACK, OUTPUT);
  pinMode(ECHO_BACK, INPUT);

  headServo.attach(SERVO_PIN);
  headServo.write(90);

  stopBot();
}

// =======================
// MAIN LOOP
// =======================
void loop() {
  if (SerialBT.available()) {
    char cmd = SerialBT.read();
    if (cmd != '\n' && cmd != '\r') {
      handleCommand(cmd);
    }
  }

  if (autoMode) {
    smartAutonomous360();
  }
}

// =======================
// COMMAND HANDLER
// =======================
void handleCommand(char c) {
  switch (c) {

    // 🚧 AUTO MODE
    case 'A':
      autoMode = true;
      break;

    // 🎮 RC FORWARD SAFETY
    case 'F':
      autoMode = false;
      if (scanFrontAt(90) < 10) {
        noGesture();
      } else {
        forward();
      }
      break;

    // 🎮 RC BACK SAFETY
    case 'B':
      autoMode = false;
      if (getBackDistance() < 10) {
        noGesture();
      } else {
        backward();
      }
      break;

    // 🎤 SAFE VOICE SHORT STEPS
    case 'U':
      autoMode = false;
      safeForwardStep();
      break;

    case 'D':
      autoMode = false;
      safeBackwardStep();
      break;

    // 🎮 RC STEERING
    case 'L':
      autoMode = false;
      left();
      break;

    case 'R':
      autoMode = false;
      right();
      break;

    // STOP
    case 'S':
      autoMode = false;
      stopBot();
      break;

    // 🎭 EXPRESSIONS
    case 'N':
      autoMode = false;
      noGesture();
      break;

    case 'G':
      autoMode = false;
      celebrationSpin();
      break;

    // ↩️ EXACT 90
    case 'Q':
      autoMode = false;
      left90();
      break;

    case 'E':
      autoMode = false;
      right90();
      break;
  }
}

// =======================
// 🎤 SAFE VOICE MOVES
// =======================
void safeForwardStep() {
  long d = scanFrontAt(90);

  if (d < 30) {
    noGesture();
    return;
  }

  forward();
  delay(300);
  stopBot();
}

void safeBackwardStep() {
  long d = getBackDistance();

  if (d < 25) {
    noGesture();
    return;
  }

  backward();
  delay(250);
  stopBot();
}

// =======================
// 🚧 SMART AUTO 360
// =======================
void smartAutonomous360() {
  long front = scanFrontAt(90);
  long back  = getBackDistance();

  // clear front
  if (front > 45) {
    forward();
    delay(220);
    stopBot();
    delay(80);
    return;
  }

  stopBot();
  delay(150);

  long leftFar  = scanFrontAt(180);
  long leftMid  = scanFrontAt(135);
  long rightMid = scanFrontAt(45);
  long rightFar = scanFrontAt(0);

  long leftAvg  = (leftFar + leftMid) / 2;
  long rightAvg = (rightFar + rightMid) / 2;

  headServo.write(90);
  delay(120);

  // reverse if back clear
  if (back > 30) {
    backward();
    delay(300);
    stopBot();
    delay(100);
  }

  // choose freer side
  if (rightAvg > leftAvg && rightAvg > 35) {
    right();
    delay(550);
  }
  else if (leftAvg > rightAvg && leftAvg > 35) {
    left();
    delay(550);
  }
  else if (back > 30) {
    backward();
    delay(250);
  }
  else {
    noGesture();
  }

  stopBot();
  delay(100);
}

// =======================
// 🎭 EXPRESSIONS
// =======================
void noGesture() {
  stopBot();

  headServo.write(0);
  delay(250);

  headServo.write(180);
  delay(250);

  headServo.write(90);
}

void celebrationSpin() {
  right();
  delay(1200);
  stopBot();
}

// =======================
// ↩️ EXACT TURNS
// =======================
void left90() {
  left();
  delay(450);
  stopBot();
}

void right90() {
  right();
  delay(450);
  stopBot();
}

// =======================
// 📏 DISTANCE HELPERS
// =======================
long scanFrontAt(int angle) {
  headServo.write(angle);
  delay(250);
  return getDistance(TRIG_FRONT, ECHO_FRONT);
}

long getBackDistance() {
  return getDistance(TRIG_BACK, ECHO_BACK);
}

long getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH, 30000);
  long distance = duration * 0.034 / 2;

  if (distance == 0) distance = 100;
  return distance;
}

// =======================
// 🚗 MOTOR CONTROL
// =======================
void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void stopBot() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}
