#pragma once

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define BAUD_PRESCALLER (((F_CPU / (115200 * 16000000))) - 1)

void USART_init(void);
void uart_tx(char c);
