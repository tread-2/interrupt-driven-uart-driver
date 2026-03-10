#ifndef UART_H
#define UART_H

#include <stdint.h>

void uart_init(uint16_t baud); // intializes UART
void uart_send(uint8_t data); // sends bytes to ring
void uart_print(const char* str); // prints characters once bytes have been sent to ring

#endif