#include <TimerOne.h>
#include "letters.h"
#include <Adafruit_NeoPixel.h>
#include <avr/pgmspace.h>
#define LED_PIN 4
#define button 9
#define LED_COUNT 180

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

uint32_t red = 0xff0000;     //strip.Color(255, 0, 0);
uint32_t orange = 0xff3c00;  //strip.Color(255, 60, 0);
uint32_t yellow = 0xff9600;  //strip.Color(255, 150, 0);
uint32_t green = 0x00ff00;   //strip.Color(0, 255, 0);
uint32_t blue = 0x009632;    //strip.Color(0, 150, 255);
uint32_t indygo = 0x0000ff;  //strip.Color(0, 0, 255);
uint32_t purple = 0x4f00ff;  //strip.Color(255, 0, 255);
uint32_t pink = 0xff0096;    //strip.Color(255, 0, 255);
uint32_t white = 0xffffff;   //strip.Color(255, 255, 255);
uint32_t black = 0x000000;   //strip.Color(0, 0, 0);

//start
uint8_t starting = true;

uint8_t buttonCounter = 0;
uint8_t prevButtonCounter = 255;
uint8_t buttonVal = 0;
uint8_t lastDebounceTime = 0;
uint8_t previous = 0;
uint8_t buttonPrev = 0;

void setup() {
  init(150);
  pinMode(button, INPUT_PULLUP);
  Timer1.initialize(15);
  Timer1.attachInterrupt(buttonPress);
  start();
}

void loop() {
  //rainbowWave();
  all();
  //drawRainbowWave();
  // drawO(0, 0);
  // drawI(2, 0);
  // drawS(3, 0);
  // drawZ(5, 0);
  // drawL(7, 0);
  // drawJ(9, 0);
  // drawT(4, 5);
}

void all() {
  switch (buttonCounter % 8) {
    case 0:
      colorEpilepsy();
      break;
    case 1:
      drawWordMoving("kamil szram", orange, 4, 50);
      break;
    case 2:
      snake();
      break;
    case 3:
      pong();
      break;
    case 4:
      stars();
      break;
    case 5:
      dots();
      break;
    case 6:
      rainbowWave();
      break;
    case 7:
      strip.clear();
      strip.show();
      break;
  }
}

// // Some functions of our own for creating animated effects -----------------

// // Fill strip pixels one after another with a color. Strip is NOT cleared
// // first; anything there will be covered pixel by pixel. Pass in color
// // (as a single 'packed' 32-bit value, which you can get by calling
// // strip.Color(red, green, blue) as shown in the loop() function above),
// // and a delay time (in milliseconds) between pixels.


// // Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// // a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// // between frames.
// void theaterChase(uint32_t color, int wait) {
//   for(int a=0; a<10; a++) {  // Repeat 10 times...
//     for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
//       strip.clear();         //   Set all pixels in RAM to 0 (off)
//       // 'c' counts up from 'b' to end of strip in steps of 3...
//       for(int c=b; c<strip.numPixels(); c += 3) {
//         strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
//       }
//       strip.show(); // Update strip with new contents
//       delay(wait);  // Pause for a moment
//     }
//   }
// }

// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    strip.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);
    strip.show();  // Update strip with new contents
    delay(wait);   // Pause for a moment
  }
}

// // Rainbow-enhanced theater marquee. Pass delay time (in ms) between frames.
// void theaterChaseRainbow(int wait) {
//   int firstPixelHue = 0;     // First pixel starts at red (hue 0)
//   for(int a=0; a<30; a++) {  // Repeat 30 times...
//     for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
//       strip.clear();         //   Set all pixels in RAM to 0 (off)
//       // 'c' counts up from 'b' to end of strip in increments of 3...
//       for(int c=b; c<strip.numPixels(); c += 3) {
//         // hue of pixel 'c' is offset by an amount to make one full
//         // revolution of the color wheel (range 65536) along the length
//         // of the strip (strip.numPixels() steps):
//         int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
//         uint32_t color = strip.gamma32(strip.ColorHSV(hue)); // hue -> RGB
//         strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
//       }
//       strip.show();                // Update strip with new contents
//       delay(wait);                 // Pause for a moment
//       firstPixelHue += 65536 / 90; // One cycle of color wheel over 90 frames
//     }
//   }
// }

void buttonPress() {
  buttonVal = !digitalRead(button);
  if (buttonVal != previous) {
    lastDebounceTime = 15;
  }
  if (lastDebounceTime != 0) {
    lastDebounceTime--;
  } else {
    if (buttonVal == 1 && buttonVal != buttonPrev) {
      if (!starting) {
        buttonCounter++;
      }
    }
    buttonPrev = buttonVal;
  }
  previous = buttonVal;
}
