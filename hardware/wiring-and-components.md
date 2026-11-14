# Hardware, Components, and Wiring

## Bill of materials

| Component | Quantity | Function |
|---|---:|---|
| ESP32 development board | 1 | Reads inputs and controls outputs |
| Digital IR sensor modules | 3 | Detect floor markers |
| Momentary push button | 1 | Simulates overload input |
| Active buzzer module | 1 | Audible overload warning |
| 16×2 LCD with I²C backpack | 1 | Displays floor and alert status |
| Breadboard | 1 | Temporary circuit assembly |
| Male-to-male jumper wires | As required | Breadboard connections |
| Male-to-female jumper wires | As required | Connections to header pins, where needed |
| USB cable | 1 | Programming and board power |

Not included in the built prototype: load cell, HX711, servo motor, door sensor, elevator drive motor, or cloud hardware.

## Pin connections

| Component | Pin | ESP32 connection |
|---|---|---|
| IR sensor 1 (Floor 1) | OUT | GPIO 13 |
| IR sensor 1 | VCC | 3.3 V |
| IR sensor 1 | GND | GND |
| IR sensor 2 (Floor 2) | OUT | GPIO 14 |
| IR sensor 2 | VCC | 3.3 V |
| IR sensor 2 | GND | GND |
| IR sensor 3 (Floor 3) | OUT | GPIO 27 |
| IR sensor 3 | VCC | 3.3 V |
| IR sensor 3 | GND | GND |
| Push button | Terminal 1 | GPIO 26 |
| Push button | Terminal 2 | GND |
| Active buzzer | + | GPIO 25* |
| Active buzzer | − | GND |
| I²C LCD | SDA | GPIO 21 |
| I²C LCD | SCL | GPIO 22 |
| I²C LCD | VCC | 5 V** |
| I²C LCD | GND | GND |

## Wiring notes

1. The button uses the ESP32 internal pull-up: one side goes to GPIO 26 and the other to GND. No external pull-up resistor is needed for this wiring.
2. The sketch assumes each IR module output is LOW when it detects its floor marker. Confirm this with the module indicator/Serial Monitor; adjust the code if the module is active HIGH.
3. Power all IR modules from 3.3 V for this wiring so their output is compatible with ESP32 logic.
4. Connect all grounds together.
5. The LCD backpack may be powered from 5 V, but verify its SDA/SCL pull-up voltage. ESP32 GPIOs are not 5 V tolerant. Use a bidirectional I²C level shifter or appropriate 3.3 V pull-ups if the backpack pulls the bus to 5 V.
6. Do not power a high-current buzzer directly from an ESP32 pin. If the module's current exceeds the GPIO rating, use a transistor driver and suitable base/gate resistor.
7. The servo is not part of this version; no servo connection is required.

See [pinout.csv](pinout.csv) for a compact pin list.
