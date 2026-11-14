# Future Scope

The following are proposed extensions and are not part of the current implemented prototype.

1. **Actual load measurement:** add a load cell and HX711 amplifier, calibrate it with known masses, and compare measured load with a defined prototype threshold.
2. **Door status sensing:** add a limit switch or suitable proximity sensor to monitor open/closed door state. A servo may be used only for a tabletop door demonstration.
3. **IoT dashboard:** use ESP32 Wi-Fi to publish floor and alert telemetry to a web dashboard or IoT platform.
4. **Event logging:** timestamp floor changes and simulated/real sensor alerts for maintenance analysis.
5. **Emergency notification:** add a properly designed communications module for a model demonstration, with clear fault handling.
6. **Improved position sensing:** use multiple markers, encoder feedback, or other suitable position sensors to improve reliability in a controlled model.
7. **Fault diagnostics:** detect sensor disagreement, disconnected sensors, and implausible state changes.

Any real elevator integration would require engineering review, certified components, independent safety circuits, applicable codes, and qualified professionals. This student prototype is not a safety controller.
