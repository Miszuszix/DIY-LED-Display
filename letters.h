#include <stdint.h>
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <avr/pgmspace.h>
#ifndef LETTERS_H
#define LETTERS_H

//init
void init(uint8_t brightness);

//start
void start();

//tetris
void drawO(uint8_t row, uint8_t column);
void drawI(uint8_t row, uint8_t column);
void drawS(uint8_t row, uint8_t column);
void drawZ(uint8_t row, uint8_t column);
void drawL(uint8_t row, uint8_t column);
void drawJ(uint8_t row, uint8_t column);
void drawT(uint8_t row, uint8_t column);

//all effects
void all();

//colorful dots mosaic effect
void dots();
void oneDot(uint8_t red, uint8_t green, uint8_t blue, uint8_t column, int offset, int8_t limit);

//colorEpilepsy effect
void colorEpilepsy();

//water random color drops effect
void stars();
void oneStar(uint8_t red, uint8_t green, uint8_t blue, uint8_t column, int offset);

//snake game simulation methods
void snake();
bool contains(int8_t array[], int8_t symbol, uint8_t length);
bool containsSnake(uint8_t x, uint8_t y);
bool containsBoundaries(uint8_t x, uint8_t y);
uint8_t pitagoras(uint8_t startX, uint8_t startY, uint8_t targetX, uint8_t targetY);

//Rainbow Wave
void rainbowWave();

//pong game simulation methods
void pong();
void movePalletes();
void drawLeftPallete(uint8_t row);
void drawRightPallete(uint8_t row);
void moveBall();

//words and letters methods
void drawWordMoving(String word, uint32_t color, uint8_t row, uint8_t wait);
void drawLetter(uint8_t letter, uint32_t color, int8_t Column, int8_t Row);

//stock methods
void colorWipe(uint32_t color, int wait);

#endif