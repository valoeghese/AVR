# Define the microcontroller
MCU = atmega328p
NAME = display_test

# Find all C source files in the src directory and subdirectories
SRC = $(shell find src -name '*.c')

# Define the output name and directory
OUTPUT_DIR = bin
OUTPUT = $(OUTPUT_DIR)/$(NAME)

# Compiler and flags
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -Os -DF_CPU=16000000UL -DSPI_PORT=PORTD

# Linker flags
LDFLAGS = #-lm

# AVRDUDE settings
PROGRAMMER = xplainedmini

# Create object files from source files
OBJ = $(patsubst src/%.c,$(OUTPUT_DIR)/tmp/%.o,$(SRC))

# Ensure the output directory exists
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(OUTPUT_DIR)/tmp: | $(OUTPUT_DIR)
	mkdir -p $(OUTPUT_DIR)/tmp

# Target to compile the program
all: $(OUTPUT).hex

# Compile object files
$(OUTPUT).elf: $(OBJ) | $(OUTPUT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Convert ELF to HEX
$(OUTPUT).hex: $(OUTPUT).elf
	avr-objcopy -O ihex $< $@

# Compile C source files to object files
$(OUTPUT_DIR)/tmp/%.o: src/%.c | $(OUTPUT_DIR)/tmp
	$(CC) $(CFLAGS) -c $< -o $@

# Flash the program to the microcontroller
upload: $(OUTPUT).hex
	avrdude -p $(MCU) -c $(PROGRAMMER) -U flash:w:$<

# Clean up generated files
clean:
	rm -f $(OUTPUT).elf $(OUTPUT).hex $(OBJ)

# Phony targets
.PHONY: all upload clean
