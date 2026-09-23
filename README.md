# Gas Leakage Detection System with Auto Cutoff

## Project Overview
This project uses an MQ-2 gas sensor and an Arduino Uno to detect gas levels. When the sensor reading rises above a threshold, the Arduino activates a buzzer, switches on an exhaust fan through a MOSFET-controlled output, and moves a servo motor as part of the gas-regulator cutoff mechanism.

## Components
- Arduino Uno
- MQ-2 gas sensor
- Servo motor
- Buzzer
- Exhaust fan
- MOSFET for fan switching
- Connecting wires and power supply

## Working Principle
1. The MQ-2 sensor sends an analog signal to Arduino pin A0.
2. The Arduino reads the sensor value and compares it with the threshold of 400 used in the supplied sketch.
3. If the reading is greater than 400, the buzzer and fan outputs are activated and the servo moves to 180 degrees.
4. Otherwise, the buzzer and fan outputs are switched off and the servo returns to 0 degrees.
5. The sensor reading is printed to the Serial Monitor at 9600 baud.

## Pin Connections
| Component | Arduino pin |
|---|---|
| MQ-2 analog output | A0 |
| Buzzer | Digital 8 |
| Fan control through MOSFET | Digital 10 |
| Servo signal | Digital 9 |

## Repository Contents
- `code/Gas_Leakage_Detection.ino` — Arduino sketch based on the program shown in the project document.
- `report/Gas-Leakage-Detection-System-with-Auto-Cutoff.pdf` — project document containing the circuit diagram and explanation.

## Safety and Calibration Note
The document describes the servo as closing the gas regulator, while its code comment calls the 180-degree movement “Open valve (cutoff).” Confirm the actual direction of the mechanical linkage and calibrate the servo positions before use. The threshold value of 400 is a demonstration setting and must be calibrated for the particular sensor and environment. This prototype is not a certified life-safety device. Do not release flammable gas to test it; use safe, supervised procedures.

## Future Scope
The project document suggests wireless communication and remote monitoring as possible future improvements.
