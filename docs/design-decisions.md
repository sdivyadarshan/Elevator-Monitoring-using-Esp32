# Design Decisions

## Decisions made for the prototype

- **ESP32 as controller:** selected as the main controller and provides GPIO plus potential future Wi-Fi capability.
- **Three IR modules:** one sensor is assigned to each modeled floor for a straightforward three-floor demonstration.
- **Active-LOW sensor assumption:** the sketch treats LOW as a detected floor marker. This must be confirmed for the actual IR modules.
- **Push button instead of load cell:** a button was used because a load cell and HX711 amplifier were not available. This is explicitly a simulated overload input, not a weight measurement.
- **LCD with I²C backpack:** reduces the number of GPIO connections; SDA is GPIO 21 and SCL is GPIO 22.
- **Buzzer alert:** provides an immediate audible indication while overload simulation is active.
- **No servo/door mechanism:** a servo motor was not used in the assembled configuration, so door actuation is outside the implemented scope.
- **Local-only operation:** the current sketch does not connect to Wi-Fi or a cloud service.

## Software behavior choices

- The last detected floor is retained when no IR sensor is currently active.
- Each IR input is checked independently so a continuously active lower-numbered sensor does not prevent a later sensor check from updating the floor.
- A debounced button press toggles overload state; the next press clears it.

## Safety boundary

This is a classroom prototype for monitoring concepts. It does not implement safety interlocks, motor control, braking, door-lock monitoring, emergency circuits, or safety certification. It must never be used to control a real elevator.
