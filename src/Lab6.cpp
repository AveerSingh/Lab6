/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/aveersingh/Lab6/src/Lab6.ino"
void setup();
void loop();
#line 1 "/Users/aveersingh/Lab6/src/Lab6.ino"
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

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  // Read voltage from TMP36 sensor
  int reading = analogRead(TMP36_PIN);
  double voltage = (reading * 3.3) / 4095.0;

  // Calculate temperature based on voltage
  double temperature = (voltage - 0.5) * 100.0;

  // Print the temperature on the display
  display.print("Temperature: ");
  display.println(temperature, 2);
  display.display();
}

