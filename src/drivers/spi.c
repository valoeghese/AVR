#include <stdint.h>
#include <avr/io.h>

void spi_init(void)
{
    // Set up data direction for SPI pins
    DDRB |= (1 << MOSI) | (1 << SCLK);
    DDRB &= ~(1 << MISO);
}

void spi_select(int8_t port)
{
    static int8_t pin_selected = -1;

    if (pin_selected >= 0) {
        // raise the select
        SPI_PORT |= (1 << port);
    }

    pin_selected = port;
    SPI_PORT &= ~(1 << port);
}

void spi_transmit(char c)
{
    
}
