SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#include "oled-wing-adafruit.h"

OledWingAdafruit display;

// Analog pin connected to the TMP36 sensor
const int TMP36_PIN = A4;

void setup()
{
  display.setup();

  display.clearDisplay();
  display.display();
}

void loop()
{
  display.loop();

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  // Read voltage from TMP36 sensor
  int reading = analogRead(TMP36_PIN);
  double voltage = (reading * 3.3) / 4095.0;

  // Calculate temperature in Celsius and Fahrenheit
  double temperatureCelsius = (voltage - 0.5) * 100.0;
  double temperatureFahrenheit = (temperatureCelsius * 9.0 / 5.0) + 32.0;

  // Print the temperature in Celsius on the display
  display.print("Temperature (C): ");
  display.println(temperatureCelsius, 2);

  // Print the temperature in Fahrenheit on the display
  display.print("Temperature (F): ");
  display.println(temperatureFahrenheit, 2);

  display.display();
}
