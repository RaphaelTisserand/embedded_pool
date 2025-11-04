#pragma once

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

void uart_init(void);
void uart_tx(char c);
