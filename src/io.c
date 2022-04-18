#include "../include/io.h"

#include <avr/io.h>


void init_pins() {

    DDRB |= _BV(PB7);
}

void set_led() {

    PORTB |= _BV(PB7);
}

void clear_led() {

    PORTB &= ~_BV(PB7);
}