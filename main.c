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

    for(i=0; i<6; i++) {
        draw_invader((i * 30) + 20, 80, i % 2);
    }

    
    while(1) {
        
        set_led();
        _delay_ms(600);

        clear_led();
        _delay_ms(400);
    }

    return 0;
}