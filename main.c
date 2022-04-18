#include <avr/io.h>
#include <util/delay.h>

#include "include/io.h"
#include "include/graphics.h"
#include "lib/lcd.h"



int main() {

    init_pins();

    init_lcd();
    set_orientation(North);

    draw_invader(80, 80);

    
    while(1) {
        
        set_led();
        _delay_ms(600);

        clear_led();
        _delay_ms(400);
    }

    return 0;
}