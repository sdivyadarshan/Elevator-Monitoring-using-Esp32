# Algorithm and Control Logic

## Inputs

- Three digital IR sensor outputs represent the three floor markers.
- A momentary push button represents a simulated overload event.

## Outputs

- 16×2 I²C LCD displays the last detected floor or overload warning.
- Active buzzer sounds while the simulated overload state is active.
- Serial Monitor reports floor and overload state.

## Algorithm

1. Initialize serial communication, GPIO modes, I²C pins (SDA 21, SCL 22), and LCD.
2. Read the three IR sensors.
3. Treat a LOW sensor output as detection (active-LOW assumption).
4. Update the stored floor when a sensor detects its marker. If no sensor is active, retain the previous floor.
5. Sample the push button and debounce its transitions.
6. On each debounced button press, toggle the overload state:
   - inactive → active: display overload and turn buzzer on;
   - active → inactive: clear overload and turn buzzer off.
7. Refresh the LCD and periodically print status to Serial Monitor.
8. Repeat continuously.

## Sensor priority

The sketch checks all three sensors independently in order 1, 2, 3. If multiple sensors are active at the same time, the last active check takes priority (Floor 3 over Floor 2 over Floor 1). In normal installation, only one floor marker should be detected at a time.

## Pseudocode

```text
INITIALIZE ESP32, LCD, sensors, button, buzzer
floor = Unknown
overload = OFF

LOOP:
    if IR1 detects: floor = Floor 1
    if IR2 detects: floor = Floor 2
    if IR3 detects: floor = Floor 3

    read and debounce button
    if a new button press occurs:
        overload = NOT overload

    if overload:
        display OVERLOAD
        buzzer = ON
    else:
        display floor
        buzzer = OFF

    periodically print status to Serial Monitor
```

## Important interpretation

The push button is only a demonstration input. It does not measure mass or determine actual passenger capacity. The IR sensors indicate model floor position; they do not provide certified elevator position feedback.
