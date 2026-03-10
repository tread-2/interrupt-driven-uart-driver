#include <avr/io.h>
#include "uart.h"

#define F_CPU 16000000UL

void uart_init(uint16_t baud) {
    
    uint16_t ubrr = (F_CPU / (16UL * baud)) - 1; // calculates the clock rate

    // set baud rate
    UBRR0H = (ubrr >> 8);
    UBRR0L = ubrr;

    // enable transmitter
    UCSR0B = (1 << TXEN0);

    // frame format: 8 data bits and 1 stop bit
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_send(uint8_t data) {
    // wait for transmitted buffer empty
    while (!(UCSR0A & (1 << UDRE0))) {
        UDR0 = data; // send data to buffer
    }
}

void uart_print(const char* str) {
    while (*str) {
        uart_send(*str++);
    }
}
