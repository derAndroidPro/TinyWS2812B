//include the library:
#include <TinyWS2812B.h>

// store number of LEDs in a variable:
int numberOfLEDs = 20;
// create an instance of TinyWS2812B:
TinyWS2812B myLEDs(2, numberOfLEDs);

void setup() {
 //nothing here
}

void loop() {
  // use a for-loop to cycle through every LED:
  for(int pos = 0; pos<numberOfLEDs; pos++){
    // turn the previous LED off and set the current LED to white:
    myLEDs.setColor(pos-1, 0, 0, 0);
    myLEDs.setColor(pos, 255, 255, 255);
    // update the LEDs:
    myLEDs.updateLeds();
    // wait 100ms until next shift of the LED:
    delay(100);
  }
  // turn the last LED off at the end:
  myLEDs.setColor(numberOfLEDs-1, 0, 0, 0);
}
