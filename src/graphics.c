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