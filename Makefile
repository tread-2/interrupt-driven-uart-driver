MCU = atmega328p
F_CPU = 16000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -Wextra -std=c11 -Iinclude

SRC = src/main.c src/uart.c
OBJ = $(SRC:.c=.o)

TARGET = uart

all: $(TARGET).hex

$(TARGET).elf: $(OBJ)
	$(CC) -mmcu=$(MCU) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o *.elf *.hex