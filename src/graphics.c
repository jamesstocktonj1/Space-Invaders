#include "../include/graphics.h"



uint16_t invader[INVADER_W][INVADER_H] = {
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

uint16_t invadera[INVADER_W][INVADER_H] = {
    RED, 
};

/*
uint16_t invader[INVADER_H][INVADER_W] = {

};
*/
/*
uint16_t invader[INVADER_W][INVADER_H] = {
    O, O, P, O, O, O, O, O, P, O, O,
    O, O, O, P, O, O, O, P, O, O, O,
    O, O, P, P, P, P, P, P, P, O, O,
    O, P, P, O, P, P, P, O, P, P, O,
    P, P, P, P, P, P, P, P, P, P, P,
    P, O, P, P, P, P, P, P, P, O, P,
    P, O, P, O, O, O, O, O, P, O, P,
    O, O, O, P, P, O, P, P, O, O, O
};*/


void draw_invader(uint8_t i, uint8_t j) {

    uint16_t x, y;
	write_cmd(COLUMN_ADDRESS_SET);
	write_data16(i);
	write_data16(i + INVADER_W - 1);
	write_cmd(PAGE_ADDRESS_SET);
	write_data16(j);
	write_data16(j + INVADER_H - 1);
	write_cmd(MEMORY_WRITE);
    for(x=0; x<INVADER_W; x++)
        for(y=0; y<INVADER_H; y++)
			write_data16(invader[x][y]);
}