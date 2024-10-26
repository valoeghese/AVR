#include <stdint.h>
#include <avr/io.h>

// SPI on ATmega328p

#define MOSI PB3
#define MISO PB4
#define SCLK PB5

void spi_init(void)
{
    // Set up data direction for SPI pins
    DDRB |= (1 << MOSI) | (1 << SCLK);
    DDRB &= ~(1 << MISO);
    // Set up SPI registers
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // enable spi, master, prescaler 16
}

void spi_select(int8_t port)
{
    static int8_t pin_selected = -1;

    if (pin_selected >= 0) {
        // raise the select
        SPI_PORT |= (1 << port);
    }

    pin_selected = port;

    if (port) {
        SPI_PORT &= ~(1 << port);
    }
}

void spi_transmit(char c)
{
    /* Start transmission */
    SPDR = cData;


    /* Wait for transmission complete */
    while(!(SPSR & (1<<SPIF)))
        ;
}
