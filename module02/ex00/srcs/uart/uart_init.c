#include <avr/interrupt.h>
#include <avr/io.h>

void uart_init(void) {
	UBRR0 = (F_CPU / (UART_BAUDRATE * 8)) - 1; // p182

	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
}
