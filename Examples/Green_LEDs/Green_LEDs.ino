// include the library:
#include <TinyWS2812B.h>

// create an instance:
TinyWS2812B myLEDs(2, 20);

void setup() {
  // use a for-loop to cycle through every position of the LED string:
  for(int pos = 0; pos<20; pos++){
    // set the color of the LED at the current position to green:
    myLEDs.setColor(pos, 0, 255, 0);
  }
  // update the LEDs:
  myLEDs.updateLeds();
}

void loop() {
  //nothing here
}
