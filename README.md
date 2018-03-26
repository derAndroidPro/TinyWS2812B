# TinyWS2812B
#### by David Augustat
TinyWS2812B is a minimalist and easy to use Arduino library for controlling WS2812B adressable LEDs.

It works with all Atmega328-based Arduino microcontrollers including Arduino Uno, Nano and Pro Mini (5v).
<br>The library is extremely small: It uses less than 1 kb of your Arduino's program storage space, which is about 3%.

### How to use this library:
**Include the library in your sketch:**
```C
#include <TinyWS2812B.h>
```
**Create an instance of TinyWS2812B:**
```C
TinyWS2812B myLeds(int dataPin, int numberOfLEDs);

//Example: Use Pin 2 as the data pin for the WS2812B-LEDs and use 20 LEDs
TinyWS2812B myLEDs(2, 20);
```
**Set the color of an LED:**
<br>Position starting with "0" as the position of the first LED.
<br>Color values are from 0 (off) to 255 (full brightness).
```C
myLEDs.setColor(int position, byte red, byte green, byte blue);

//Example: Set the color of the fifth LED to red:
myLEDs.setColor(4, 255, 0, 0);
```
**Update the LEDs:**
<br>Has to be called to apply the changes to the LEDs.
```C
myLEDs.updateLEDs();
```
### Example: Set all LEDs to green
```C
// include the library:
#include <TinyWS2812B.h>

// create an instance:
TinyWS2812B myLEDs(4, 20);

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
```
### Example: Chasing LED Animation
```C
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
```
### Licensing
This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
  International License.
  To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
  or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.

  When you use or redistribute this library, you MUST credit me using following link:
  https://github.com/derAndroidPro/TinyWS2812B

