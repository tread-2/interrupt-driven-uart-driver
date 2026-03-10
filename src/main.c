#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

int main(void) {
    uart_init(9600);

    while (1) {
        uart_print("Hello from AVR\r\n");
        _delay_ms(1000);
    }
}