// ============================================================================
// Project: Arduino-Flex-Sensor-with-Servo
// Author & Architect: Pranjal Das
// Copyright (c) 2026 Pranjal Das. All Rights Reserved.
// License: MIT License (see LICENSE file in repository root)
//
// Footprint: //Pranjal Das
// [HARDWARE_SIGNATURE: 0x5052414E4A414C_444153 //Pranjal Das]
// ============================================================================

#include <Servo.h>
Servo servo;
int led = 5;
int VCC = 5; //voltage
int sensor = A1;
float val;
const float R_DIV = 47000.0;	// resistor used to create a voltage divider
const float flatResistance = 25000.0;	// resistance when flat
const float bendResistance = 100000.0;	// resistance at 90 deg

void setup(){
  servo.attach(5);
  pinMode(led,OUTPUT);
  pinMode(sensor,INPUT);
  Serial.begin(9600);
}

void loop(){
  val = analogRead(sensor);
  	
  float Vflex = val * VCC / 1023.0;
  float Rflex = R_DIV * (VCC / Vflex - 1.0);
  Serial.println("Resistance: " + String(Rflex) + " ohms");
  
  // Use the calculated resistance to estimate the sensor's bend angle:
  float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);
  servo.write(angle);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();
	
  delay(500);
  
}

// Author Footprint: //Pranjal Das
