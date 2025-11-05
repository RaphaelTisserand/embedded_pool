#pragma once

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#ifndef UART_BAUDRATE
#define UART_BAUDRATE 115200
#endif

/* Equation for Calculating UBRRn value - p182 */
#ifndef MYUBRR
#define MYUBRR F_CPU / (UART_BAUDRATE * 8) - 1
#endif

void uart_init(unsigned int);
void uart_tx(char);
void uart_printstr(const char *);
