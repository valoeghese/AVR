#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#include "drivers/spi.h"

#define LED_PIN PB5

void wait(uint8_t hms) {
    for(uint8_t i = 0; i < hms; i++)
        _delay_ms(100);
}

void blink(uint8_t delay) {
    // Turn on the LED
    PORTB |= (1 << LED_PIN);
    wait(delay/2); // Wait for 1 second

    // Turn off the LED
    PORTB &= ~(1 << LED_PIN);
    wait(delay/2); // Wait for 1 second
}

int main(void) {
    // Set LED_PIN as output
    DDRB |= (1 << LED_PIN);

    while (1) {
        for (uint8_t i = 0; i < 3; i++) {
            uint8_t delay = i == 1 ? 10 : 5;

            for (uint8_t j = 0; j < 3; j++) {
                blink(delay);
            }
        }

        _delay_ms(1000);
    }
    return 0;
}
