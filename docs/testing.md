# Testing Checklist and Observations

> Record actual results during your bench test. No pass/fail results are claimed in this document until they are observed and entered by the project team.

## Pre-power checks

- [ ] Confirm ESP32 board and USB cable.
- [ ] Confirm common GND between ESP32, sensors, LCD, and buzzer circuit.
- [ ] Verify IR sensor VCC is 3.3 V and outputs are compatible with ESP32.
- [ ] Verify LCD backpack I²C pull-up voltage is safe for ESP32 GPIO.
- [ ] Verify buzzer current is within the GPIO drive arrangement or use a transistor driver.
- [ ] Check for breadboard shorts before powering.

## Functional test checklist

| Test | Procedure | Expected behavior | Actual result |
|---|---|---|---|
| LCD startup | Power/reset ESP32 | Startup message appears, then floor screen | Not recorded |
| Floor 1 | Present marker to IR1 | LCD reports Floor 1 | Not recorded |
| Floor 2 | Present marker to IR2 | LCD reports Floor 2 | Not recorded |
| Floor 3 | Present marker to IR3 | LCD reports Floor 3 | Not recorded |
| Floor hold | Remove marker from all sensors | Last detected floor remains displayed | Not recorded |
| Overload activation | Press button once | LCD shows overload; buzzer sounds | Not recorded |
| Overload clear | Press button again | Alert clears; buzzer stops | Not recorded |
| Button debounce | Press and release normally | One state change per press | Not recorded |
| Serial output | Open Serial Monitor at 115200 baud | Status lines are printed | Not recorded |

## Troubleshooting

- **LCD blank/blue:** verify 5 V/GND, SDA 21, SCL 22, I²C address (configured as 0x27), and contrast potentiometer. Run an I²C scanner.
- **IR floor not detected:** confirm sensor OUT logic level, adjust the onboard sensitivity potentiometer, align the sensor and marker, and verify GPIO assignment.
- **Buzzer does not sound:** confirm active buzzer polarity, module type, common ground, and driver circuit.
- **Button triggers repeatedly:** check button wiring to GND and GPIO 26, then verify debounce settings.

## Test record

- Test date: ____________________
- ESP32 board variant: ____________________
- LCD I²C address: ____________________
- IR output polarity observed: ____________________
- Notes / measured observations: ____________________
