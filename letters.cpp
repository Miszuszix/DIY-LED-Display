#include <stdint.h>
#include "Arduino.h"
#include "letters.h"
#include <Adafruit_NeoPixel.h>
#include <avr/pgmspace.h>

const PROGMEM uint8_t ledsHorizontal[12][15] = { { 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 },
                                                 { 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 },
                                                 { 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30 },
                                                 { 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59 },
                                                 { 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60 },
                                                 { 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89 },
                                                 { 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90 },
                                                 { 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119 },
                                                 { 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120 },
                                                 { 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149 },
                                                 { 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150 },
                                                 { 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179 } };
const PROGMEM uint8_t A[5][4] = { { 0, 1, 1, 0 },
                                  { 1, 0, 0, 1 },
                                  { 1, 1, 1, 1 },
                                  { 1, 0, 0, 1 },
                                  { 1, 0, 0, 1 } };

const PROGMEM uint8_t B[5][4] = { { 1, 1, 1, 0 },
                                  { 1, 0, 0, 1 },
                                  { 1, 1, 1, 0 },
                                  { 1, 0, 0, 1 },
                                  { 1, 1, 1, 0 } };

const PROGMEM uint8_t C[5][4] = { { 0, 1, 1, 0 },
                                  { 1, 0, 0, 1 },
                                  { 1, 0, 0, 0 },
                                  { 1, 0, 0, 1 },
                                  { 0, 1, 1, 0 } };

const PROGMEM uint8_t D[5][4] = { { 1, 1, 1, 0 },
                                  { 1, 0, 0, 1 },
                                  { 1, 0, 0, 1 },
                                  { 1, 0, 0, 1 },
                                  { 1, 1, 1, 0 } };

const PROGMEM uint8_t E[5][4] = { { 1, 1, 1, 1 },
                                  { 1, 0, 0, 0 },
                                  { 1, 1, 1, 0 },
                                  { 1, 0, 0, 0 },
                                  { 1, 1, 1, 1 } };

const PROGMEM uint8_t F[5][4] = { { 1, 1, 1, 1 },
                                  { 1, 0, 0, 0 },
                                  { 1, 1, 1, 0 },
                                  { 1, 0, 0, 0 },
                                  { 1, 0, 0, 0 } };

const PROGMEM uint8_t G[5][4] = { { 0, 1, 1, 1 },
                                  { 1, 0, 0, 0 },
                                  { 1, 0, 1, 1 },
                                  { 1, 0, 0, 1 },
                                  { 0, 1, 1, 1 } };

const PROGMEM uint8_t H[5][4] = { { 1, 0, 0, 1 },
                                  { 1, 0, 0, 1 },
                                  { 1, 1, 1, 1 },
                                  { 1, 0, 0, 1 },
                                  { 1, 0, 0, 1 } };

const PROGMEM uint8_t I[5][3] = { { 1, 1, 1 },
                                  { 0, 1, 0 },
                                  { 0, 1, 0 },
                                  { 0, 1, 0 },
                                  { 1, 1, 1 } };

const PROGMEM uint8_t J[5][4] = { { 0, 1, 1, 1 },
                                  { 0, 0, 1, 0 },
                                  { 0, 0, 1, 0 },
                                  { 1, 0, 1, 0 },
                                  { 0, 1, 1, 0 } };

const PROGMEM uint8_t K[5][4] = { { 1, 0, 0, 1 },
                                  { 1, 0, 1, 0 },
                                  { 1, 1, 0, 0 },
                                  { 1, 0, 1, 0 },
                                  { 1, 0, 0, 1 } };

const PROGMEM uint8_t L[5][3] = { { 1, 0, 0 },
                                  { 1, 0, 0 },
                                  { 1, 0, 0 },
                                  { 1, 0, 0 },
                                  { 1, 1, 1 } };

const PROGMEM uint8_t M[5][5] = { { 1, 0, 0, 0, 1 },
                                  { 1, 1, 0, 1, 1 },
                                  { 1, 0, 1, 0, 1 },
                                  { 1, 0, 0, 0, 1 },
                                  { 1, 0, 0, 0, 1 } };

const PROGMEM uint8_t N[5][4] = { { 1, 0, 0, 1 },
                                  { 1, 1, 0, 1 },
                                  { 1, 0, 1, 1 },
                                  { 1, 0, 0, 1 },
                                  { 1, 0, 0, 1 } };

const PROGMEM uint8_t O[5][4] = { { 0, 1, 1, 0 },
                                  { 1, 0, 0, 1 },
                                  { 1, 0, 0, 1 },
                                  { 1, 0, 0, 1 },
                                  { 0, 1, 1, 0 } };

const PROGMEM uint8_t P[5][4] = { { 1, 1, 1, 0 },
                                  { 1, 0, 0, 1 },
                                  { 1, 1, 1, 0 },
                                  { 1, 0, 0, 0 },
                                  { 1, 0, 0, 0 } };

const PROGMEM uint8_t Q[5][4] = { { 0, 1, 1, 0 },
                                  { 1, 0, 0, 1 },
                                  { 1, 0, 0, 1 },
                                  { 1, 0, 1, 0 },
                                  { 0, 1, 0, 1 } };

const PROGMEM uint8_t R[5][4] = { { 1, 1, 1, 0 },
                                  { 1, 0, 0, 1 },
                                  { 1, 1, 1, 0 },
                                  { 1, 0, 1, 0 },
                                  { 1, 0, 0, 1 } };

const PROGMEM uint8_t S[5][4] = { { 0, 1, 1, 1 },
                                  { 1, 0, 0, 0 },
                                  { 0, 1, 1, 0 },
                                  { 0, 0, 0, 1 },
                                  { 1, 1, 1, 0 } };

const PROGMEM uint8_t T[5][5] = { { 1, 1, 1, 1, 1 },
                                  { 0, 0, 1, 0, 0 },
                                  { 0, 0, 1, 0, 0 },
                                  { 0, 0, 1, 0, 0 },
                                  { 0, 0, 1, 0, 0 } };

const PROGMEM uint8_t U[5][4] = { { 1, 0, 0, 1 },
                                  { 1, 0, 0, 1 },
                                  { 1, 0, 0, 1 },
                                  { 1, 0, 0, 1 },
                                  { 0, 1, 1, 0 } };

const PROGMEM uint8_t V[5][5] = { { 1, 0, 0, 0, 1 },
                                  { 1, 0, 0, 0, 1 },
                                  { 0, 1, 0, 1, 0 },
                                  { 0, 1, 0, 1, 0 },
                                  { 0, 0, 1, 0, 0 } };

const PROGMEM uint8_t W[5][5] = { { 1, 0, 0, 0, 1 },
                                  { 1, 0, 0, 0, 1 },
                                  { 1, 0, 1, 0, 1 },
                                  { 1, 1, 0, 1, 1 },
                                  { 1, 0, 0, 0, 1 } };

const PROGMEM uint8_t X[5][5] = { { 1, 0, 0, 0, 1 },
                                  { 0, 1, 0, 1, 0 },
                                  { 0, 0, 1, 0, 0 },
                                  { 0, 1, 0, 1, 0 },
                                  { 1, 0, 0, 0, 1 } };

const PROGMEM uint8_t Y[5][5] = { { 1, 0, 0, 0, 1 },
                                  { 0, 1, 0, 1, 0 },
                                  { 0, 0, 1, 0, 0 },
                                  { 0, 0, 1, 0, 0 },
                                  { 0, 0, 1, 0, 0 } };

const PROGMEM uint8_t Z[5][4] = { { 1, 1, 1, 1 },
                                  { 0, 0, 0, 1 },
                                  { 0, 1, 1, 0 },
                                  { 1, 0, 0, 0 },
                                  { 1, 1, 1, 1 } };

const PROGMEM uint8_t qst[5][4] = { { 0, 1, 1, 1 },
                                    { 0, 0, 0, 1 },
                                    { 0, 1, 1, 1 },
                                    { 0, 0, 0, 0 },
                                    { 0, 1, 0, 0 } };

const PROGMEM uint8_t spc[5][1] = { { 0 },
                                    { 0 },
                                    { 0 },
                                    { 0 },
                                    { 0 } };

const PROGMEM uint8_t exc[5][1] = { { 1 },
                                    { 1 },
                                    { 1 },
                                    { 0 },
                                    { 1 } };

const PROGMEM uint8_t coma[5][2] = { { 0, 0 },
                                     { 0, 0 },
                                     { 0, 0 },
                                     { 0, 1 },
                                     { 1, 0 } };

const PROGMEM uint8_t zero[5][4] = { { 0, 1, 1, 0 },
                                     { 1, 0, 1, 1 },
                                     { 1, 1, 1, 1 },
                                     { 1, 1, 0, 1 },
                                     { 0, 1, 1, 0 } };

const PROGMEM uint8_t one[5][4] = { { 0, 0, 1, 0 },
                                    { 0, 1, 1, 0 },
                                    { 1, 1, 1, 0 },
                                    { 0, 0, 1, 0 },
                                    { 0, 1, 1, 1 } };

const PROGMEM uint8_t two[5][4] = { { 0, 1, 1, 0 },
                                    { 1, 0, 0, 1 },
                                    { 0, 0, 1, 0 },
                                    { 0, 1, 0, 0 },
                                    { 1, 1, 1, 1 } };

const PROGMEM uint8_t three[5][4] = { { 0, 1, 1, 0 },
                                      { 1, 0, 0, 1 },
                                      { 0, 0, 1, 1 },
                                      { 1, 0, 0, 1 },
                                      { 0, 1, 1, 0 } };

const PROGMEM uint8_t four[5][4] = { { 0, 0, 1, 1 },
                                     { 0, 1, 0, 1 },
                                     { 1, 1, 1, 1 },
                                     { 0, 0, 0, 1 },
                                     { 0, 0, 0, 1 } };

const PROGMEM uint8_t five[5][4] = { { 1, 1, 1, 1 },
                                     { 1, 1, 1, 0 },
                                     { 0, 0, 0, 1 },
                                     { 1, 0, 0, 1 },
                                     { 0, 1, 1, 0 } };

const PROGMEM uint8_t six[5][4] = { { 0, 0, 1, 0 },
                                    { 0, 1, 0, 0 },
                                    { 1, 1, 1, 0 },
                                    { 1, 0, 0, 1 },
                                    { 0, 1, 1, 0 } };

const PROGMEM uint8_t seven[5][4] = { { 1, 1, 1, 1 },
                                      { 0, 0, 0, 1 },
                                      { 0, 0, 1, 0 },
                                      { 0, 1, 0, 0 },
                                      { 1, 0, 0, 0 } };

const PROGMEM uint8_t eight[5][4] = { { 0, 1, 1, 0 },
                                      { 1, 0, 0, 1 },
                                      { 0, 1, 1, 0 },
                                      { 1, 0, 0, 1 },
                                      { 0, 1, 1, 0 } };

const PROGMEM uint8_t nine[5][4] = { { 0, 1, 1, 0 },
                                     { 1, 0, 0, 1 },
                                     { 0, 1, 1, 1 },
                                     { 0, 0, 1, 0 },
                                     { 0, 1, 0, 0 } };

const uint8_t width1[2] = { ' ', '!' };
const uint8_t width2[1] = { ',' };
const uint8_t width3[2] = { 'I', 'L' };
const uint8_t width4[29] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'N', 'O', 'P', 'Q', 'R', 'S', 'U', 'Z', '?', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
const uint8_t width5[6] = { 'M', 'W', 'V', 'X', 'Y', 'T' };

//snake
uint8_t snakeContains[302] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
uint8_t snakeLength = 10;
uint8_t snakeX = 1;
uint8_t snakeY = 1;

//pong
uint8_t ballX = 6;
uint8_t ballY = 1;
uint8_t prevballX = 5;
uint8_t prevballY = 0;
bool up = false;
bool right = true;
uint8_t prevRight = 4;
uint8_t prevLeft = 4;
uint8_t leftPos = 4;
uint8_t rightPos = 4;

//rainbow wave
int8_t positions[15] = { -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5 };
uint8_t rising[15] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 };

//dots or stars
uint8_t colors[45];
uint8_t redMix = 0;
uint8_t greenMix = 0;
uint8_t blueMix = 0;
uint8_t limits[15] = { 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11 };

//start
extern uint8_t starting;

//rainbowSine
uint8_t index = 0;

extern const uint32_t red;
extern const uint32_t halfred;
extern const uint32_t orange;
extern const uint32_t halforange;
extern const uint32_t yellow;
extern const uint32_t halfyellow;
extern const uint32_t green;
extern const uint32_t halfgreen;
extern const uint32_t blue;
extern const uint32_t halfblue;
extern const uint32_t indygo;
extern const uint32_t halfindygo;
extern const uint32_t purple;
extern const uint32_t halfpurple;
extern const uint32_t pink;

extern const uint32_t black;
extern const uint32_t white;

uint8_t color[15][3] = { { 255, 0, 0 },
                         { 255, 180, 0 },
                         { 255, 230, 0 },
                         { 0, 255, 0 },
                         { 0, 120, 255 },
                         { 0, 0, 255 },
                         { 255, 0, 255 },
                         { 255, 0, 150 },
                         { 255, 0, 0 },
                         { 255, 180, 0 },
                         { 255, 230, 0 },
                         { 0, 255, 0 },
                         { 0, 120, 255 },
                         { 0, 0, 255 },
                         { 255, 0, 255 } };

extern const Adafruit_NeoPixel strip;

extern uint8_t buttonCounter;

void init(uint8_t brightness) {
  Serial.begin(9600);
  strip.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.clear();
  strip.show();
  strip.setBrightness(strip.gamma8(brightness));  // Set BRIGHTNESS to about 1/5 (max = 255)
}

void rainbowWave() {
  uint8_t display;
  uint8_t offset = 15;
  for (int j = 0; j < 17; j++) {
    if (buttonCounter % 8 != 6) {
      break;
    }
    strip.clear();
    for (uint8_t i = 0; i < 15; i++) {
      for (int k = -3; k < 1; k++) {
        if ((strip.sine8((i + j) * offset) / 25) + k >= 0 && (strip.sine8((i + j) * offset) / 25) + k <= 11) {
          display = pgm_read_byte(&ledsHorizontal[(strip.sine8((i + j) * offset) / 25) + k][i]);
          uint8_t factor = int(((1 - k) + 1) * 0.5);
          strip.setPixelColor(display, strip.Color(strip.gamma8(color[i][0] / factor), strip.gamma8(color[i][1] / factor), strip.gamma8(color[i][2] / factor)));
        }
      }
      for (int k = 1; k < 5; k++) {
        if ((strip.sine8((i + j) * offset) / 25) + k >= 0 && (strip.sine8((i + j) * offset) / 25) + k <= 11) {
          display = pgm_read_byte(&ledsHorizontal[(strip.sine8((i + j) * offset) / 25) + k][i]);
          uint8_t factor = int((k + 1) * 0.5);
          strip.setPixelColor(display, strip.Color(strip.gamma8(color[i][0] / factor), strip.gamma8(color[i][1] / factor), strip.gamma8(color[i][2] / factor)));
        }
      }
    }
    strip.show();
    delay(60);
    uint8_t temp[3];
    for (int i = 0; i < 3; i++) {
      temp[i] = color[0][i];
    }
    for (int i = 0; i < 14; i++) {
      for (int j = 0; j < 3; j++) {
        color[i][j] = color[i + 1][j];
      }
    }
    for (int i = 0; i < 3; i++) {
      color[14][i] = temp[i];
    }
  }
}

void drawT(uint8_t row, uint8_t column) {
  for (int i = 0; i < 3; i++) {
    strip.setPixelColor(pgm_read_byte(&ledsHorizontal[11 - row - i][column]), purple);
  }
  strip.setPixelColor(pgm_read_byte(&ledsHorizontal[11 - row - 1][column + 1]), purple);
  strip.show();
}

void drawJ(uint8_t row, uint8_t column) {
  strip.setPixelColor(pgm_read_byte(&ledsHorizontal[11 - row][column + 2]), pink);
  for (int i = 0; i < 3; i++) {
    strip.setPixelColor(pgm_read_byte(&ledsHorizontal[10 - row][column + i]), pink);
  }
  strip.show();
}

void drawL(uint8_t row, uint8_t column) {
  for (int i = 0; i < 3; i++) {
    strip.setPixelColor(pgm_read_byte(&ledsHorizontal[11 - row][column + i]), orange);
  }
  strip.setPixelColor(pgm_read_byte(&ledsHorizontal[10 - row][column + 2]), orange);
  strip.show();
}

void drawZ(uint8_t row, uint8_t column) {
  for (int i = 0; i < 2; i++) {
    strip.setPixelColor(pgm_read_byte(&ledsHorizontal[11 - row][column + i + 1]), green);
    strip.setPixelColor(pgm_read_byte(&ledsHorizontal[10 - row][column + i]), green);
  }
  strip.show();
}

void drawS(uint8_t row, uint8_t column) {
  for (int i = 0; i < 2; i++) {
    strip.setPixelColor(pgm_read_byte(&ledsHorizontal[11 - row][column + i]), red);
    strip.setPixelColor(pgm_read_byte(&ledsHorizontal[10 - row][column + i + 1]), red);
  }
  strip.show();
}

void drawI(uint8_t row, uint8_t column) {
  for (int i = 0; i < 4; i++) {
    strip.setPixelColor(pgm_read_byte(&ledsHorizontal[11 - row][column + i]), blue);
  }
  strip.show();
}

void drawO(uint8_t row, uint8_t column) {
  for (int i = 0; i < 2; i++) {
    strip.setPixelColor(pgm_read_byte(&ledsHorizontal[11 - row][column + i]), yellow);
    strip.setPixelColor(pgm_read_byte(&ledsHorizontal[10 - row][column + i]), yellow);
  }
  strip.show();
}

void start() {
  for (int i = 0; i < 3; i++) {
    uint8_t display = pgm_read_byte(&ledsHorizontal[0][i]);
    strip.setPixelColor(display, green);
    strip.show();
    delay(1000);
  }
  //drawWordMoving("witaj adrian!", green, 4, 50);
  starting = false;
}

void dots() {
  strip.clear();
  for (int i = 0; i < 15; i++) {
    limits[i] = 11;
  }
  int8_t offsets[15] = { 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12 };
  int8_t number = 0;
  for (int j = 0; j < 15; j++) {
    number = random(-80, -6);
    while (contains(offsets, number, 15)) {
      number = random(-80, -6);
    }
    offsets[j] = number;
    colors[j * 3] = random(50, 256);
    colors[j * 3 + 1] = random(50, 256);
    colors[j * 3 + 2] = random(50, 256);
  }
  while (true) {
    if (buttonCounter % 8 != 5) {
      break;
    }
    for (int j = 0; j < 15; j++) {
      oneDot(colors[j * 3], colors[j * 3 + 1], colors[j * 3 + 2], j, offsets[j], limits[j]);
      offsets[j]++;
      if (offsets[j] == 12) {
        number = random(-80, -6);
        while (contains(offsets, number, 15)) {
          number = random(-80, -6);
        }
        offsets[j] = number;
        colors[j * 3] = random(50, 256);
        colors[j * 3 + 1] = random(50, 256);
        colors[j * 3 + 2] = random(50, 256);
      }
    }
    for (int j = 0; j < 15; j++) {
      bool restart = false;
      if (limits[j] == 255) {
        restart = true;
      }
      if (restart) {
        for (int i = 0; i < 12; i++) {
          uint8_t display = pgm_read_byte(&ledsHorizontal[i][j]);
          strip.setPixelColor(display, black);
        }
        limits[j] = 11;
      }
    }
    strip.show();
    delay(50);
  }
}

void stars() {
  int8_t offsets[15] = { 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12 };
  int8_t number = 0;
  for (int j = 0; j < 15; j++) {
    number = random(-80, -6);
    while (contains(offsets, number, 15)) {
      number = random(-80, -6);
    }
    offsets[j] = number;
    colors[j * 3] = random(50, 256);
    colors[j * 3 + 1] = random(50, 256);
    colors[j * 3 + 2] = random(50, 256);
  }
  while (true) {
    if (buttonCounter % 8 != 4) {
      break;
    }
    strip.clear();
    for (int j = 0; j < 15; j++) {
      oneStar(colors[j * 3], colors[j * 3 + 1], colors[j * 3 + 2], j, offsets[j]);
      offsets[j]++;
      if (offsets[j] == 12) {
        number = random(-80, -6);
        while (contains(offsets, number, 15)) {
          number = random(-80, -6);
        }
        offsets[j] = number;
        colors[j * 3] = random(50, 256);
        colors[j * 3 + 1] = random(50, 256);
        colors[j * 3 + 2] = random(50, 256);
      }
    }
    strip.show();
    delay(75);
  }
}

void oneStar(uint8_t red, uint8_t green, uint8_t blue, uint8_t column, int offset) {
  for (int j = 0; j < 7; j++) {
    if (j + offset < 0 || j + offset > 11) {

    } else {
      uint8_t display = pgm_read_byte(&ledsHorizontal[j + offset][column]);
      strip.setPixelColor(display, strip.Color(strip.gamma8(red / 7 * (j + 1)), strip.gamma8(green / 7 * (j + 1)), strip.gamma8(blue / 7 * (j + 1))));
    }
  }
}

void oneDot(uint8_t red, uint8_t green, uint8_t blue, uint8_t column, int offset, int8_t limit) {
  uint8_t display;
  if (offset < limit + 1 && offset > 0) {
    display = pgm_read_byte(&ledsHorizontal[offset][column]);
    strip.setPixelColor(display, strip.Color(red, green, blue));
    display = pgm_read_byte(&ledsHorizontal[offset - 1][column]);
    strip.setPixelColor(display, black);
  } else if (offset == 0 && limit >= 0) {
    display = pgm_read_byte(&ledsHorizontal[offset][column]);
    strip.setPixelColor(display, strip.Color(red, green, blue));
  }
  if (offset == limit) {
    limits[column]--;
  }
}


void colorEpilepsy() {
  for (int i = 0; i < 256; i++) {
    strip.setPixelColor(i, strip.Color(random(0, 256), random(0, 256), random(0, 256)));
  }
  strip.show();
  delay(50);
}

void drawLeftPallete(uint8_t row) {
  uint8_t display;
  for (uint8_t i = prevLeft; i < prevLeft + 3; i++) {
    display = pgm_read_byte(&ledsHorizontal[i][0]);
    strip.setPixelColor(display, black);
  }
  for (uint8_t i = row; i < row + 3; i++) {
    display = pgm_read_byte(&ledsHorizontal[i][0]);
    strip.setPixelColor(display, white);
  }
}

void drawRightPallete(uint8_t row) {
  uint8_t display;
  for (uint8_t i = prevRight; i < prevRight + 3; i++) {
    display = pgm_read_byte(&ledsHorizontal[i][0]);
    strip.setPixelColor(display, black);
  }
  for (uint8_t i = row; i < row + 3; i++) {
    display = pgm_read_byte(&ledsHorizontal[i][14]);
    strip.setPixelColor(display, white);
  }
}

void movePalletes() {
  if (right) {
    if (ballX > rightPos) {
      if (rightPos + 1 >= 10) {
        rightPos = 9;
      } else {
        rightPos++;
      }
    } else {
      if (rightPos - 1 <= -1) {
        rightPos = 0;
      } else {
        rightPos--;
      }
    }
    drawRightPallete(rightPos);
    drawLeftPallete(leftPos);
  } else {
    if (ballX > leftPos) {
      if (leftPos + 1 >= 10) {
        leftPos = 9;
      } else {
        leftPos++;
      }
    } else {
      if (leftPos - 1 <= -1) {
        leftPos = 0;
      } else {
        leftPos--;
      }
    }
    drawRightPallete(rightPos);
    drawLeftPallete(leftPos);
  }
}

void moveBall() {
  uint8_t display;
  display = pgm_read_byte(&ledsHorizontal[ballX][ballY]);
  strip.setPixelColor(display, white);
  display = pgm_read_byte(&ledsHorizontal[prevballX][prevballY]);
  strip.setPixelColor(display, black);
  prevballX = ballX;
  prevballY = ballY;
  if (up) {
    if (ballX - 1 == -1) {
      up = false;
      ballX++;
    } else {
      ballX--;
    }
  } else {
    if (ballX + 1 == 12) {
      up = true;
      ballX--;
    } else {
      ballX++;
    }
  }
  if (right) {
    if (ballY + 1 == 14) {
      right = false;
      ballY--;
    } else {
      ballY++;
    }
  } else {
    if (ballY - 1 == 0) {
      right = true;
      ballY++;
    } else {
      ballY--;
    }
  }
  strip.show();
}

void pong() {
  strip.clear();
  movePalletes();
  moveBall();
  delay(125);
}

void snake() {
  uint8_t appleX = random(1, 14);
  uint8_t appleY = random(1, 11);
  while (true) {
    if (buttonCounter % 8 != 2) {
      break;
    }
    strip.clear();
    for (int i = 14; i >= 0; i--) {
      strip.setPixelColor(i, white);
    }
    for (int i = 165; i < 180; i++) {
      strip.setPixelColor(i, white);
    }
    for (int i = 14; i < 166; i += 30) {
      strip.setPixelColor(i, white);
      strip.setPixelColor(i + 1, white);
    }

    for (int i = 0; i < 180; i += 30) {
      strip.setPixelColor(i, white);
      strip.setPixelColor(i + 29, white);
    }
    uint8_t free[4] = { 255, 255, 255, 255 };
    uint8_t display;
    if (snakeX == appleX && snakeY == appleY) {
      appleX = random(1, 14);
      appleY = random(1, 11);
      while (containsSnake(appleX, appleY)) {
        appleX = random(1, 14);
        appleY = random(1, 10);
      }
    }
    for (int i = 0; i < snakeLength * 2; i += 2) {
      display = pgm_read_byte(&ledsHorizontal[snakeContains[i + 1]][snakeContains[i]]);
      if (i == snakeLength * 2 - 2) {
        strip.setPixelColor(display, strip.Color(0, 150, 255));
      } else if (i == 0) {
        strip.setPixelColor(display, black);
      } else {
        strip.setPixelColor(display, green);
      }
    }
    display = pgm_read_byte(&ledsHorizontal[appleY][appleX]);
    strip.setPixelColor(display, red);
    strip.show();
    delay(250);
    uint8_t mini = 255;

    for (int i = 0; i < snakeLength * 2 - 2; i += 2) {
      snakeContains[i] = snakeContains[i + 2];
      snakeContains[i + 1] = snakeContains[i + 3];
    }

    if (!containsSnake(snakeX + 1, snakeY) && !containsBoundaries(snakeX + 1, snakeY)) {
      free[0] = pitagoras(snakeX + 1, snakeY, appleX, appleY);
      if (free[0] < mini) { mini = free[0]; }
    }
    if (!containsSnake(snakeX - 1, snakeY) && !containsBoundaries(snakeX - 1, snakeY)) {
      free[1] = pitagoras(snakeX - 1, snakeY, appleX, appleY);
      if (free[1] < mini) { mini = free[1]; }
    }
    if (!containsSnake(snakeX, snakeY + 1) && !containsBoundaries(snakeX, snakeY + 1)) {
      free[2] = pitagoras(snakeX, snakeY + 1, appleX, appleY);
      if (free[2] < mini) { mini = free[2]; }
    }
    if (!containsSnake(snakeX, snakeY - 1) && !containsBoundaries(snakeX, snakeY - 1)) {
      free[3] = pitagoras(snakeX, snakeY - 1, appleX, appleY);
      if (free[3] < mini) { mini = free[3]; }
    }

    if (free[0] == mini) {
      snakeX++;
      snakeContains[snakeLength * 2 - 2] = snakeX;
      snakeContains[snakeLength * 2 - 1] = snakeY;
    } else if (free[1] == mini) {
      snakeX--;
      snakeContains[snakeLength * 2 - 2] = snakeX;
      snakeContains[snakeLength * 2 - 1] = snakeY;
    } else if (free[2] == mini) {
      snakeY++;
      snakeContains[snakeLength * 2 - 2] = snakeX;
      snakeContains[snakeLength * 2 - 1] = snakeY;
    } else {
      snakeY--;
      snakeContains[snakeLength * 2 - 2] = snakeX;
      snakeContains[snakeLength * 2 - 1] = snakeY;
    }
  }
}

uint8_t pitagoras(uint8_t startX, uint8_t startY, uint8_t targetX, uint8_t targetY) {
  uint8_t result = sqrt(pow(startX - targetX, 2) + pow(startY - targetY, 2));
  return result;
}

void drawWordMoving(String word, uint32_t color, uint8_t row, uint8_t wait) {
  int length = word.length();
  int width = 0;
  for (int i = 14; i >= length * -5; i--) {
    if (!starting) {
      if (buttonCounter % 8 != 1) {
        break;
      }
    }
    int offset = 0;
    strip.clear();
    for (int j = 0; j < length; j++) {
      char bigLetter = toupper(word.charAt(j));
      if (contains(width1, bigLetter, sizeof(width1))) {
        width = 2;
      } else if (contains(width2, bigLetter, sizeof(width2))) {
        width = 3;
      } else if (contains(width3, bigLetter, sizeof(width3))) {
        width = 4;
      } else if (contains(width4, bigLetter, sizeof(width4))) {
        width = 5;
      } else if (contains(width5, bigLetter, sizeof(width5))) {
        width = 6;
      }
      if (i + offset >= -5 && i + offset <= 14) {
        drawLetter(bigLetter, color, i + offset, row);
      }
      offset += width;
    }
    strip.show();
    delay(wait);
  }
}

void drawLetter(uint8_t letter, const uint32_t color, int8_t row, int8_t column) {
  uint8_t cursor;
  uint8_t display;
  char bigLetter = toupper(letter);
  for (byte i = 0; i < 5; i++) {
    if (contains(width1, bigLetter, sizeof(width1))) {
      for (byte j = 0; j < 1; j++) {
        switch (bigLetter) {
          case ' ':
            cursor = pgm_read_byte(&spc[i][j]);
            break;
          case '!':
            cursor = pgm_read_byte(&exc[i][j]);
            break;
        }
        if (cursor) {
          if (i + column >= 0 && i + column <= 11 && j + row >= 0 && j + row <= 14) {
            display = pgm_read_byte(&ledsHorizontal[i + column][j + row]);
            strip.setPixelColor(display, color);
          }
        }
      }
    } else if (contains(width2, bigLetter, sizeof(width2))) {
      for (byte j = 0; j < 2; j++) {
        switch (bigLetter) {
          case ',':
            cursor = pgm_read_byte(&coma[i][j]);
            break;
        }
        if (cursor) {
          if (i + column >= 0 && i + column <= 11 && j + row >= 0 && j + row <= 14) {
            display = pgm_read_byte(&ledsHorizontal[i + column + 1][j + row]);
            strip.setPixelColor(display, color);
          }
        }
      }
    } else if (contains(width3, bigLetter, sizeof(width3))) {
      for (byte j = 0; j < 3; j++) {
        switch (bigLetter) {
          case 'I':
            cursor = pgm_read_byte(&I[i][j]);
            break;
          case 'L':
            cursor = pgm_read_byte(&L[i][j]);
            break;
        }
        if (cursor) {
          if (i + column >= 0 && i + column <= 11 && j + row >= 0 && j + row <= 14) {
            display = pgm_read_byte(&ledsHorizontal[i + column][j + row]);
            strip.setPixelColor(display, color);
          }
        }
      }
    } else if (contains(width4, bigLetter, sizeof(width4))) {
      for (byte j = 0; j < 4; j++) {
        switch (bigLetter) {
          case 'A':
            cursor = pgm_read_byte(&A[i][j]);
            break;
          case 'B':
            cursor = pgm_read_byte(&B[i][j]);
            break;
          case 'C':
            cursor = pgm_read_byte(&C[i][j]);
            break;
          case 'D':
            cursor = pgm_read_byte(&D[i][j]);
            break;
          case 'E':
            cursor = pgm_read_byte(&E[i][j]);
            break;
          case 'F':
            cursor = pgm_read_byte(&F[i][j]);
            break;
          case 'G':
            cursor = pgm_read_byte(&G[i][j]);
            break;
          case 'H':
            cursor = pgm_read_byte(&H[i][j]);
            break;
          case 'J':
            cursor = pgm_read_byte(&J[i][j]);
            break;
          case 'K':
            cursor = pgm_read_byte(&K[i][j]);
            break;
          case 'N':
            cursor = pgm_read_byte(&N[i][j]);
            break;
          case 'O':
            cursor = pgm_read_byte(&O[i][j]);
            break;
          case 'P':
            cursor = pgm_read_byte(&P[i][j]);
            break;
          case 'Q':
            cursor = pgm_read_byte(&Q[i][j]);cvvvvvv                                                               
          case 'U':
            cursor = pgm_read_byte(&U[i][j]);
            break;
          case 'Z':
            cursor = pgm_read_byte(&Z[i][j]);
            break;
          case '?':                                                     
            cursor = pgm_read_byte(&qst[i][j]);
            break;
          case '0':
            cursor = pgm_read_byte(&zero[i][j]);
            break;
          case '1':
            cursor = pgm_read_byte(&one[i][j]);
            break;
          case '2':
            cursor = pgm_read_byte(&two[i][j]);
            break;
          case '3':
            cursor = pgm_read_byte(&three[i][j]);
            break;
          case '4':
            cursor = pgm_read_byte(&four[i][j]);
            break;
          case '5':
            cursor = pgm_read_byte(&five[i][j]);
            break;
          case '6':
            cursor = pgm_read_byte(&six[i][j]);
            break;
          case '7':
            cursor = pgm_read_byte(&seven[i][j]);
            break;
          case '8':
            cursor = pgm_read_byte(&eight[i][j]);
            break;
          case '9':
            cursor = pgm_read_byte(&nine[i][j]);
            break;
        }
        if (cursor) {
          if (i + column >= 0 && i + column <= 11 && j + row >= 0 && j + row <= 14) {
            display = pgm_read_byte(&ledsHorizontal[i + column][j + row]);
            strip.setPixelColor(display, color);
          }
        }
      }
    } else if (contains(width5, bigLetter, sizeof(width5))) {
      for (byte j = 0; j < 5; j++) {
        switch (bigLetter) {
          case 'M':
            cursor = pgm_read_byte(&M[i][j]);
            break;
          case 'V':
            cursor = pgm_read_byte(&V[i][j]);
            break;
          case 'W':
            cursor = pgm_read_byte(&W[i][j]);
            break;
          case 'X':
            cursor = pgm_read_byte(&X[i][j]);
            break;
          case 'Y':
            cursor = pgm_read_byte(&Y[i][j]);
            break;
          case 'T':
            cursor = pgm_read_byte(&T[i][j]);
            break;
        }
        if (cursor) {
          if (i + column >= 0 && i + column <= 11 && j + row >= 0 && j + row <= 14) {
            display = pgm_read_byte(&ledsHorizontal[i + column][j + row]);
            strip.setPixelColor(display, color);
          }
        }
      }
    }
  }
  //strip.show();
}

bool contains(int8_t array[], int8_t symbol, uint8_t length) {
  for (int i = 0; i < length; i++) {
    if (symbol == array[i]) {
      return true;
    }
  }
  return false;
}

bool containsSnake(uint8_t x, uint8_t y) {
  for (int i = 0; i < 302; i += 2) {
    if (x == snakeContains[i] && y == snakeContains[i + 1]) {
      return true;
    }
  }
  return false;
}

bool containsBoundaries(uint8_t x, uint8_t y) {
  if (x <= 0 || x >= 14 || y <= 0 || y >= 11) {
    return true;
  }
  return false;
}

void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < strip.numPixels(); i++) {  // For each pixel in strip...
    strip.setPixelColor(i, color);               //  Set pixel's color (in RAM)
    strip.show();                                //  Update strip to match
    delay(wait);                                 //  Pause for a moment
  }
}