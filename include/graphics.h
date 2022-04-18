#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../lib/lcd.h"
#include "../lib/ili934x.h"
#include "game.h"


#define INVADER_W 22
#define INVADER_H 16

#define INVADER_COL WHITE


//simplified for graphics array
#define P INVADER_COL
#define O 0x0000


extern uint16_t invaderA[INVADER_W][INVADER_H];
extern uint16_t invaderB[INVADER_W][INVADER_H];

void draw_invader(uint8_t i, uint8_t j, uint8_t type);
void draw_screen(uint8_t x, uint8_t y, uint8_t type, uint8_t* array, uint8_t arrayLen);

#endif