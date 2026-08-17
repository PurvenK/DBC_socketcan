# AI Usage Report

## AI Tool Selected

ChatGPT

## Purpose of AI Usage

ChatGPT was used to assist in the development, validation, and documentation of the DBC file and SocketCAN implementation.

## Prompts Used

1. Generate a DBC file for Vehicle Speed, Engine RPM, Coolant Temperature, Fuel Level, and Battery Voltage.

2. Review the DBC file and identify possible errors, inefficient signal layouts, missing documentation, and naming improvements.

3. Provide a SocketCAN transmitter implementation in C for the defined signals.

4. Add an Ambient Temperature signal and update the DBC and transmitter.

## AI Generated Outputs

- Initial DBC file structure.
- Signal definitions and scaling factors.
- SocketCAN transmitter implementation guidance.
- Ambient Temperature signal definition.
- DBC validation recommendations.

## Corrections Performed

- Verified signal ranges and engineering units.
- Updated DBC syntax for compatibility with SavvyCAN.
- Added Ambient Temperature signal.
- Validated decoded values using SavvyCAN.
- Verified scaling factors and offsets.

## Challenge 4: AI Review

### Possible Errors

No major syntax errors were identified after validation.

### Inefficient Signal Layout

The signal layout was acceptable for a simple educational CAN network. All signals fit within a single 8-byte CAN frame.

### Missing Documentation

The AI suggested documenting signal ranges, scaling factors, units, and message descriptions.

### Naming Improvements

Signal names such as VehicleSpeed, EngineRPM, CoolantTemp, FuelLevel, BatteryVoltage, and AmbientTemp were considered clear and meaningful.

### Evaluation

The suggestions were useful for validating the DBC file and improving documentation. No major changes to the signal layout were required.

## Final Observations

AI reduced the effort required to create and validate the DBC file. However, all generated content was manually reviewed and verified before use.
