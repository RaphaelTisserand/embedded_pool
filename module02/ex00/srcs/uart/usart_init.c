#include <avr/interrupt.h>
#include <avr/io.h>

void USART_init(void) {
	UBRR0H = (uint8_t)(BAUD_PRESCALLER >> 8);
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = ((1 << UCSZ00) | (1 << UCSZ01));
}
