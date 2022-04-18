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

    for(i=0; i<6; i++) {
        //draw_invader((i * 30) + 20, 80, i % 2);
    }

    
    while(1) {

        for(row=0; row<10; row++) {

            for(column=0; column<10; column++) {

                for(i=0; i<6; i++) {
                    if((row % 2) == 0) {
                        draw_invader((i * 30) + (column * 6), row * 8, column % 2);
                    }
                    else {
                        draw_invader((i * 30) + (60 - (column * 6)), row * 8, column % 2);
                    }
                    
                }

                clearArea.left = 0;
                clearArea.right = LCDWIDTH;
                clearArea.top = row * 8;
                clearArea.bottom = row * 8 + INVADER_H;

                

                set_led();
                _delay_ms(600);

                clear_led();
                _delay_ms(400);

                fill_rectangle(clearArea, 0x0000);
            }
        }
        
        
    }

    return 0;
}