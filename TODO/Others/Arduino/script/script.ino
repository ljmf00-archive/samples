/*lsferreira programming */
#include "pitches.h"

int led = 9;
int brightness = 0;
int fadeAmount = 5;
int melody[] = {NOTE_G3, NOTE_C4};
int noteDurations[] = {8, 4};

void setup() {
  for (int thisNote = 0; thisNote < 2; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(2);}
  pinMode(led, OUTPUT);}
void loop() {
  analogWrite(led, brightness);
  brightness = brightness + fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; }
  delay(30); }
