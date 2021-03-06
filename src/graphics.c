#include "../include/graphics.h"



uint16_t invaderA[INVADER_W][INVADER_H] = {
    O, O, O, O, P, P, O, O, O, O, O, O, O, O, O, O, P, P, O, O, O, O, 
    O, O, O, O, P, P, O, O, O, O, O, O, O, O, O, O, P, P, O, O, O, O, 
    O, O, O, O, O, O, P, P, O, O, O, O, O, O, P, P, O, O, O, O, O, O, 
    O, O, O, O, O, O, P, P, O, O, O, O, O, O, P, P, O, O, O, O, O, O, 
    O, O, O, O, P, P, P, P, P, P, P, P, P, P, P, P, P, P, O, O, O, O, 
    O, O, O, O, P, P, P, P, P, P, P, P, P, P, P, P, P, P, O, O, O, O, 
    O, O, P, P, P, P, O, O, P, P, P, P, P, P, O, O, P, P, P, P, O, O, 
    O, O, P, P, P, P, O, O, P, P, P, P, P, P, O, O, P, P, P, P, O, O, 
    P, P, O, O, P, P, P, P, P, P, P, P, P, P, P, P, P, P, O, O, P, P, 
    P, P, O, O, P, P, P, P, P, P, P, P, P, P, P, P, P, P, O, O, P, P, 
    P, P, O, O, P, P, P, P, P, P, P, P, P, P, P, P, P, P, O, O, P, P, 
    P, P, O, O, P, P, P, P, P, P, P, P, P, P, P, P, P, P, O, O, P, P, 
    P, P, O, O, P, P, O, O, O, O, O, O, O, O, O, O, P, P, O, O, P, P, 
    P, P, O, O, P, P, O, O, O, O, O, O, O, O, O, O, P, P, O, O, P, P,  
    O, O, O, O, O, O, P, P, P, P, O, O, P, P, P, P, O, O, O, O, O, O, 
    O, O, O, O, O, O, P, P, P, P, O, O, P, P, P, P, O, O, O, O, O, O
};

uint16_t invaderB[INVADER_W][INVADER_H] = {
    O, O, O, O, P, P, O, O, O, O, O, O, O, O, O, O, P, P, O, O, O, O, 
    P, P, O, O, P, P, O, O, O, O, O, O, O, O, O, O, P, P, O, O, P, P, 
    P, P, O, O, O, O, P, P, O, O, O, O, O, O, P, P, O, O, O, O, P, P, 
    P, P, O, O, O, O, P, P, O, O, O, O, O, O, P, P, O, O, O, O, P, P, 
    P, P, O, O, P, P, P, P, P, P, P, P, P, P, P, P, P, P, O, O, P, P, 
    P, P, O, O, P, P, P, P, P, P, P, P, P, P, P, P, P, P, O, O, P, P, 
    O, O, P, P, P, P, O, O, P, P, P, P, P, P, O, O, P, P, P, P, O, O, 
    O, O, P, P, P, P, O, O, P, P, P, P, P, P, O, O, P, P, P, P, O, O, 
    O, O, O, O, P, P, P, P, P, P, P, P, P, P, P, P, P, P, O, O, O, O, 
    O, O, O, O, P, P, P, P, P, P, P, P, P, P, P, P, P, P, O, O, O, O, 
    O, O, O, O, P, P, P, P, P, P, P, P, P, P, P, P, P, P, O, O, O, O, 
    O, O, O, O, P, P, P, P, P, P, P, P, P, P, P, P, P, P, O, O, O, O, 
    O, O, O, O, P, P, O, O, O, O, O, O, O, O, O, O, P, P, O, O, O, O, 
    O, O, O, O, P, P, O, O, O, O, O, O, O, O, O, O, P, P, O, O, O, O,  
    O, O, P, P, O, O, O, O, O, O, O, O, O, O, O, O, O, O, P, P, O, O, 
    O, O, P, P, O, O, O, O, O, O, O, O, O, O, O, O, O, O, P, P, O, O
};

uint16_t blaster[BLASTER_W][BLASTER_H] = {
    O, O, O, O, O, O, O, O, O, O, P, P, O, O, O, O, O, O, O, O, O, O, 
    O, O, O, O, O, O, O, O, O, O, P, P, O, O, O, O, O, O, O, O, O, O, 
    O, O, O, O, O, O, O, O, P, P, P, P, P, P, O, O, O, O, O, O, O, O, 
    O, O, O, O, O, O, O, O, P, P, P, P, P, P, O, O, O, O, O, O, O, O, 
    O, O, O, O, O, O, O, O, P, P, P, P, P, P, O, O, O, O, O, O, O, O, 
    O, O, O, O, O, O, O, O, P, P, P, P, P, P, O, O, O, O, O, O, O, O, 
    O, O, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, O, O, 
    O, O, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, O, O, 
    P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, 
    P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, 
    P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, 
    P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, 
    P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, 
    P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P, P
};



void draw_invader(uint8_t i, uint8_t j, uint8_t type) {

    uint16_t x, y;

	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(i);
	write_data16(i + INVADER_W - 1);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(j);
	write_data16(j + INVADER_H - 1);
	write_cmd(MEMORY_WRITE);

    for(x=0; x<INVADER_W; x++) {
        for(y=0; y<INVADER_H; y++) {
            if(type) {
                write_data16(invaderB[x][y]);
            }
            else {
                write_data16(invaderA[x][y]);
            }
        }
    }
}


void draw_screen(uint8_t x, uint8_t y, uint8_t type, uint8_t* array, uint8_t arrayLen) {

    uint8_t i, j;

    for(i=0; i<arrayLen; i++) {

        for(j=0; j<array[i]; j++) {
            draw_invader(x + (i * ITEM_WIDTH), y + (j * ROW_HEIGHT), type);
        }
    }
}

void draw_blaster(uint8_t i) {

    uint16_t x, y;

	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(i);
	write_data16(i + BLASTER_W - 1);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(LCDHEIGHT - BLASTER_H);
	write_data16(LCDHEIGHT);
	write_cmd(MEMORY_WRITE);

    for(x=0; x<BLASTER_W; x++) {
        for(y=0; y<BLASTER_H; y++) {
            write_data16(blaster[x][y]);
        }
    }
}

rectangle get_blaster_outline(uint8_t i) {

    rectangle r;
    r.left = i;
    r.right = i + BLASTER_W - 1;
    r.top = LCDHEIGHT - BLASTER_H;
    r.bottom = LCDHEIGHT;

    return r;
}