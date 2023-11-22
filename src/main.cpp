#include <Arduino.h>

int distance = 0;

// param: ADC proximity width
int RESOLUTION = 4;

// 'autotune' mapping of distances to notes
// cut off at ends observed in testing
int notes[16] = {0, 0, 0, 0, 60, 62, 64, 65, 67, 69, 71, 72, 0, 0, 0, 0};

void setup()
{
  // baud rate of MIDI protocol
  Serial.begin(31250);

  // set the resolution (0-4096)
  analogReadResolution(RESOLUTION);
}

void loop()
{
  distance = analogRead(3);
  int note = notes[distance];
  // Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
  Serial.write(0x90);
  Serial.write(note);
  Serial.write(0x45);
  delay(100);
}
