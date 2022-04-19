#include <avr/io.h>
#include <util/delay.h>

#include "include/io.h"
#include "include/graphics.h"
#include "lib/lcd.h"



int main() {

    init_pins();

    init_lcd();
    set_orientation(North);

    int i;

    int row, column;
    rectangle clearArea;
    rectangle blasterClearArea;

    for(i=0; i<6; i++) {
        //draw_invader((i * 30) + 20, 80, i % 2);
    }

    uint8_t arr[6] = {4, 2, 0, 1, 2, 4};

    
    while(1) {

        for(row=0; row<10; row++) {

            clearArea.left = 0;
            clearArea.right = LCDWIDTH;
            clearArea.top = row * ROW_INCREMENT;
            clearArea.bottom = (row * ROW_INCREMENT) + (4 * ROW_HEIGHT);

            for(column=0; column<10; column++) {

                draw_blaster(column * 20);
                blasterClearArea = get_blaster_outline(column * 20);

                if((row % 2) == 0) {
                    //draw_invader((i * 30) + (column * 6), (row * 8) + (j * 20), column % 2);
                    draw_screen(column * COLUMN_INCREMENT + 4, row * ROW_INCREMENT, column % 2, arr, 6);

                }
                else {
                    //draw_invader((i * 30) + (60 - (column * 6)), (row * 8) + (j * 20), column % 2);
                    draw_screen((10 * COLUMN_INCREMENT) - (column * COLUMN_INCREMENT) + 4, row * ROW_INCREMENT, column % 2, arr, 6);
                }


                set_led();
                _delay_ms((10 - row) * 50);

                clear_led();
                _delay_ms((10 - row) * 50);

                fill_rectangle(clearArea, 0x0000);
                fill_rectangle(blasterClearArea, 0x0000);
            }
        }
        
        
    }

    return 0;
}