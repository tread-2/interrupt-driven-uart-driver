# AVR UART DRIVER (ATmega328P) #

A minimal UART driver implementation for the ATmega328P written in C using avr-gcc. This project demonstrates how to configure and use this micocontroller's hardware UART for serial comunication with a PC terminal.

The goal of this project is to build a foundational embedded driver and progressively expand it into a non-blocking interrupt-driven UART implementation 

## Features ##
- UART intialization with configurable baud rate
- Blocking UART transmisson function
- String transmission over serial
- Minimal driver abstraction
- Build system with avr-gcc and make

## Project Structure ##

- include
    - uart.h        # UART driver interface
- src
    - uart.c        # UART driver implementation
    - main.c        # Application layer
Makefile            # Build config
README.md

## Hardware ##

Microcontroller target: ATmega328P
Clock Frequency: 16MHz

## Build Instructions ##

Required avr toolchain is installed:
- avr-gcc
- avr-libc
- avr-objcopy
- make

Building the project

- make

This will generate:

- uart.elf
- uart.hex

## Flashing the Microcontroller ##

avrdude -c arduino -p atmega328p -P /dev/ttyUSB0 -b 115200 -U flash:w:uart.hex

(Port may vary depending on your system)

## Serial Output ##

After flashing the microcontroller, connect via serial terminal:

screen /dev/ttyUSB0 9600

Expected output:

Hello from AVR
Hello from AVR
Hello from AVR

## Improvements ##

Some enhancements may include:

- Interrupt-driven UART RX
- Ring buffer implementation
- Command parsing from serial input
- Non-blocking UART communication

## Learning Objectives ##

This project demonstrates seceral core embedded system concepts:

- Direct register manipulation
- UART hardware manipulation
- Embedded driver architecture
- AVR build systems
- Serial communication protocols

## License ##

This project is provided for education purposes