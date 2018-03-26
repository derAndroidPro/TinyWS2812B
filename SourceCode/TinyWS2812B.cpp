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


#include "Arduino.h"
#include "TinyWS2812B.h"

TinyWS2812B::TinyWS2812B(int pin, int ledCount){
  numLeds = ledCount;
  pinMode(pin, OUTPUT);
  findHardwarePortAndPin(pin);
}

void TinyWS2812B::findHardwarePortAndPin(int pin){
  // find port:
  if(pin >= 8 && pin <= 13){
    //port B
    port = 1;
  } else if(pin >= 14 && pin <= 19){
    // port C
    port = 2;
  } else if(pin >= 2 && pin <= 7){
    // port D
    port = 3;
  }

  // find bit of port:
  if(pin == 8 || pin == 14){
    //0
    portOn =  B00000001;
    portOff = B11111110;
  } else if(pin == 9 || pin == 15){
    //1
    portOn =  B00000010;
    portOff = B11111101;
  } else if(pin == 10 || pin == 16 || pin == 2){
    //2
    portOn =  B00000100;
    portOff = B11111011;
  } else if(pin == 11 || pin == 17 || pin == 3){
    //3
    portOn =  B00001000;
    portOff = B11110111;
  } else if(pin == 12 || pin == 18 || pin == 4){
    //4
    portOn =  B00010000;
    portOff = B11101111;
  } else if(pin == 13 || pin == 19 || pin == 5){
    //5
    portOn =  B00100000;
    portOff = B11011111;
  } else if(pin == 6){
    //6
    portOn =  B01000000;
    portOff = B10111111;
  } else if(pin == 7){
    //7
    portOn =  B10000000;
    portOff = B01111111;
    }
}

void TinyWS2812B::setColor(int pos, byte r, byte g, byte b){
  if(pos >= 0 && pos<numLeds){
    // position 0 can't be used when array size is unknown -> Shift every position by one
    colorData[pos+1][0] = r;
    colorData[pos+1][1] = g;
    colorData[pos+1][2] = b;
  }
}

void TinyWS2812B::updateLeds(){
  cli(); // disable interrupts during writing
  for(int i = 0; i<numLeds; i++){
     writeByte(colorData[i+1][1]);
     writeByte(colorData[i+1][0]);
     writeByte(colorData[i+1][2]);
  }
  sei(); //reenable interrupts after data has been written
  delay(1);
}

void TinyWS2812B::writeByte(byte dataByte){
  switch(port){
     // Port B
     case 1:
       for(int i = 7; i > -1; i--){
         if(!bitRead(dataByte, i)){
           zeroB();
         } else {
           oneB();
         }
       }
       break;
     // Port C:
     case 2:
       for(int i = 7; i > -1; i--){
         if(!bitRead(dataByte, i)){
           zeroC();
         } else {
           oneC();
         }
       }
       break;
      // Port D:
     case 3:
       for(int i = 7; i > -1; i--){
         if(!bitRead(dataByte, i)){
           zeroD();
         } else {
           oneD();
         }
       }
      break;
   }
}

void TinyWS2812B::oneB(){
  PORTB |= portOn;    // delay: 0.8 microseconds
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");

  PORTB &= portOff;   // delay: 0.45 microseconds
  __asm__("nop\n\t");
}

void TinyWS2812B::zeroB(){
  PORTB |= portOn;    // delay: 0.4 microseconds

  PORTB &= portOff;   // delay: 0.85 microseconds
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
}

void TinyWS2812B::oneC(){
  PORTC |= portOn;    // delay: 0.8 microseconds
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");

  PORTC &= portOff;   // delay: 0.45 microseconds
  __asm__("nop\n\t");
}

void TinyWS2812B::zeroC(){
  PORTC |= portOn;    // delay: 0.4 microseconds

  PORTC &= portOff;   // delay: 0.85 microseconds
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
}

void TinyWS2812B::oneD(){
  PORTD |= portOn;    // delay: 0.8 microseconds
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");

  PORTD &= portOff;   // delay: 0.45 microseconds
  __asm__("nop\n\t");
}

void TinyWS2812B::zeroD(){
  PORTD |= portOn;    // delay: 0.4 microseconds

  PORTD &= portOff;   // delay: 0.85 microseconds
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
  __asm__("nop\n\t");
}
