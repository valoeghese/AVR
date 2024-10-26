/*
 * spi.h
 * Header for Serial-Peripheral Interface.
 * SPI chip select is set up on SPI_PORT, which should be defined in your buildscript.
 */

#include <stdint.h>

void spi_init(void); // set up SPI
void spi_select(int8_t port);
void spi_transmit(char c);

