/*
 * spi.h
 * Header for Serial-Peripheral Interface.
 * SPI is set up on SPI_PORT, which should be defined in your buildscript.
 * SPI locations:
 * - MOSI / PB0
 * - 
 */

#include <stdint.h>

#define MOSI PB0
#define MISO PB1
#define SCLK PB2

void spi_init(void); // set up SPI
void spi_select(int8_t port);
void spi_transmit(char c);

