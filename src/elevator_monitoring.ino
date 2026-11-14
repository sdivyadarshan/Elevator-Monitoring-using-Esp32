/*
  Project: ESP32-Based Elevator Monitoring System
  Prototype: 3-floor IR position indication + simulated overload alert.

  Hardware:
    IR floor 1 OUT -> GPIO 13
    IR floor 2 OUT -> GPIO 14
    IR floor 3 OUT -> GPIO 27
    Overload button -> GPIO 26 to GND (INPUT_PULLUP)
    Active buzzer + -> GPIO 25
    I2C LCD SDA -> GPIO 21
    I2C LCD SCL -> GPIO 22

  Assumptions:
    - IR sensor outputs are active LOW.
    - LCD I2C address is 0x27.
    - The buzzer is an active type and its current is within a safe
      GPIO drive arrangement. Use a transistor driver if needed.

  Educational prototype only; not for controlling a real elevator.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

constexpr uint8_t IR1_PIN = 13;
constexpr uint8_t IR2_PIN = 14;
constexpr uint8_t IR3_PIN = 27;
constexpr uint8_t BUTTON_PIN = 26;
constexpr uint8_t BUZZER_PIN = 25;

constexpr unsigned long DEBOUNCE_MS = 45;

const char *floorStatus = "Floor ?";
bool overloadActive = false;

bool lastRawButtonState = HIGH;
bool stableButtonState = HIGH;
unsigned long lastButtonChangeMs = 0;

void updateFloor() {
  // Read all sensors independently. If more than one is active,
  // the highest-numbered active sensor wins (3 > 2 > 1).
  // When none is active, retain the last detected floor.
  if (digitalRead(IR1_PIN) == LOW) {
    floorStatus = "Floor 1";
  }
  if (digitalRead(IR2_PIN) == LOW) {
    floorStatus = "Floor 2";
  }
  if (digitalRead(IR3_PIN) == LOW) {
    floorStatus = "Floor 3";
  }
}

void handleButton() {
  const bool rawState = digitalRead(BUTTON_PIN);

  if (rawState != lastRawButtonState) {
    lastButtonChangeMs = millis();
    lastRawButtonState = rawState;
  }

  if ((millis() - lastButtonChangeMs) >= DEBOUNCE_MS &&
      rawState != stableButtonState) {
    stableButtonState = rawState;

    // Toggle only on the debounced press edge.
    if (stableButtonState == LOW) {
      overloadActive = !overloadActive;
      Serial.println(overloadActive
                         ? "OVERLOAD ALERT: ACTIVE"
                         : "OVERLOAD ALERT: CLEARED");
    }
  }
}

void updateOutputs() {
  digitalWrite(BUZZER_PIN, overloadActive ? HIGH : LOW);

  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");

  if (overloadActive) {
    lcd.setCursor(0, 0);
    lcd.print("!!! OVERLOAD !!!");
    lcd.setCursor(0, 1);
    lcd.print("CHECK LIFT");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Current Floor:");
    lcd.setCursor(0, 1);
    lcd.print(floorStatus);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(IR1_PIN, INPUT);
  pinMode(IR2_PIN, INPUT);
  pinMode(IR3_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("ELEVATOR SYSTEM");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(1500);
  lcd.clear();

  Serial.println("Elevator monitoring prototype ready.");
}

void loop() {
  updateFloor();
  handleButton();
  updateOutputs();

  static unsigned long lastStatusPrintMs = 0;
  if (millis() - lastStatusPrintMs >= 1000) {
    lastStatusPrintMs = millis();
    Serial.print("Current floor: ");
    Serial.print(floorStatus);
    Serial.print(" | Overload: ");
    Serial.println(overloadActive ? "ACTIVE" : "CLEAR");
  }

  delay(10);
}
