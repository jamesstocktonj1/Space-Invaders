#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../lib/lcd.h"
#include "../lib/ili934x.h"


#define INVADER_W 22
#define INVADER_H 16

#define INVADER_COL WHITE



#define P INVADER_COL
#define O 0x0000

uint16_t invader[INVADER_W][INVADER_H];
//uint16_t invader[INVADER_H * INVADER_W];
uint16_t inv[INVADER_H][INVADER_W];



void draw_invader(uint8_t x, uint8_t y);


#endif