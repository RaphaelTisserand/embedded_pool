#include "include.h"

void uart_init(unsigned int ubrr) {
	/* Double the USART Transmission Speed - p201 */
	UCSR0A |= (1 << U2X0);

	/* Set baud rate - p185 */
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;

	/* Writing this bit to one enables the USART Transmitter. - p202 */
	UCSR0B = (1 << TXEN0);

	/* Set frame format: 8-bit format - p203 */
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}
