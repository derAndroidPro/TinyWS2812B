/*
  TinyWS2812B (Version 1.0)

  TinyWS2812B - A minimalist and easy to use Arduino library for controlling
  WS2812B adressable LEDs.

  This library was created by David Augustat in 2018. (https://github.com/derAndroidPro)

  This work is licensed under the Creative Commons Attribution-ShareAlike 4.0
  International License.
  To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
  or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.

  When you use or redistribute this library, you MUST credit me using following link:
  https://github.com/derAndroidPro/TinyWS2812B

  This library is designed for use with a clock frequency of 16Mhz.
  (compatible with Arduino Uno, Arduino Nano, Arduino Pro Mini 5V,...)
*/

#ifndef TinyWS2812B_h
#define TinyWS2812B_h

#include "Arduino.h"

class TinyWS2812B{
  public:
    TinyWS2812B(int pin, int ledCount);
    void setColor(int pos, byte r, byte g, byte b);
    void updateLeds();

  private:
    byte port;
    byte portOn;
    byte portOff;
    byte colorData[][3];
    int numLeds;
    void findHardwarePortAndPin(int pin);
    void writeByte(byte dataByte);
    void oneB();
    void zeroB();
    void oneC();
    void zeroC();
    void oneD();
    void zeroD();
};

#endif
