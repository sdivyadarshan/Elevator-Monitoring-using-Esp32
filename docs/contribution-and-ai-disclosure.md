# Contribution and AI-Assistance Disclosure

This document distinguishes the project work described by the student from assistance used to prepare the repository package. It should be reviewed and edited by the student so it accurately reflects the work personally completed.

## Student contribution (based on the project discussion)

- Chose and developed the ESP32-based elevator monitoring mini-project.
- Assembled the prototype around an ESP32, three IR sensor modules, a push button, an active buzzer, and a 16×2 I²C LCD.
- Connected the LCD using GPIO 21 (SDA) and GPIO 22 (SCL).
- Tested the LCD and worked through display/I²C troubleshooting.
- Defined the floor mapping (IR1 → Floor 1, IR2 → Floor 2, IR3 → Floor 3).
- Chose a push button to simulate overload because a load cell and HX711 were unavailable.
- Tested the floor indication and overload demonstration behavior as described in the project conversation.

The student should add any additional original circuit design, physical model construction, calibration, debugging, or test work actually performed.

## AI-assisted work

AI assistance was used to:
- organize the repository structure and engineering documentation;
- draft and refine the Arduino sketch and its comments;
- describe the algorithm, architecture, design decisions, and testing checklist;
- prepare the README and wiring tables.

## Verification responsibility

The student is responsible for reviewing the source code, checking pin assignments against the physical board, validating electrical safety, performing the tests, and ensuring that the final report accurately describes the built prototype. AI-generated documentation or code should not be represented as wholly independent student-authored work.

## Testing disclosure

Only tests actually performed should be marked as passed. The repository testing checklist leaves results as “Not recorded” until the student enters observed results.
