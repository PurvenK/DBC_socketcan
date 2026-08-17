# Technical Report

## 1. Introduction

This project demonstrates the complete CAN communication workflow using SocketCAN, DBC files, and SavvyCAN. The objective was to design CAN messages, generate traffic, decode signals using a DBC file, and visualize engineering values.

## 2. Signal Design

The following signals were implemented:

- Vehicle Speed (0–120 km/h)
- Engine RPM (800–5000 rpm)
- Coolant Temperature (20–120 °C)
- Fuel Level (0–100 %)
- Battery Voltage (11–15 V)
- Ambient Temperature (0–50 °C)

All signals were transmitted using CAN ID 0x100.

## 3. DBC Structure

A DBC file named vehicle.dbc was created to define:

- Message identifier
- Signal positions
- Signal lengths
- Scaling factors
- Engineering units
- Minimum and maximum values

The DBC file enabled automatic decoding of raw CAN frames.

## 4. Validation Process

The DBC file was validated using SavvyCAN.

Validation included:

- Signal decoding verification
- Range verification
- Unit verification
- Scaling factor verification

All signals decoded correctly after validation.

## 5. SocketCAN Integration

A C-based SocketCAN transmitter was implemented.

The transmitter periodically generated realistic values for:

- Vehicle Speed
- Engine RPM
- Coolant Temperature
- Fuel Level
- Battery Voltage

The application transmitted CAN frames over the virtual CAN interface vcan0.

## 6. CAN Data Visualization

SavvyCAN was connected to vcan0.

The vehicle.dbc file was imported into SavvyCAN, allowing raw CAN frames to be decoded into engineering values.

The decoded values were displayed in real time using the signal viewer.

## 7. Raw Data vs Decoded Data

Raw CAN Frame Example:

ID: 0x100
DATA: 78 00 AC 0D 76 02 77 19

Decoded Signals:

VehicleSpeed = 120 km/h
EngineRPM = 3500 rpm
CoolantTemp = 118 °C
FuelLevel = 2 %
BatteryVoltage = 11.9 V
AmbientTemp = 25 °C

The DBC file converts hexadecimal data into meaningful engineering values.

## 8. Challenge Results

Challenge 1:
Raw CAN frames and decoded signals were compared and analyzed.

Challenge 2:
The Battery Voltage scaling factor was modified from 0.1 to 0.2. The displayed voltage became incorrect, demonstrating the importance of correct DBC definitions.

Challenge 3:
An Ambient Temperature signal was added to the CAN message, DBC file, and transmitter application. The signal was successfully decoded.

Challenge 4:
ChatGPT reviewed the DBC file and suggested validation of signal ranges, scaling factors, naming conventions, and documentation.

## 9. Lessons Learned

- DBC files are essential for interpreting CAN messages.
- SocketCAN provides a simple environment for CAN development.
- DBC-based decoding simplifies signal analysis.
- AI tools can assist in DBC development and validation.
- Signal scaling and offsets must be carefully verified.

## 10. Conclusion

The project successfully demonstrated CAN message design, DBC development, SocketCAN communication, signal decoding, and real-time visualization using SavvyCAN.
