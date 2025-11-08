#include "include.h"

char uart_rx(void) {
	/* Wait for empty transmit buffer - p186/200 */
	while (!(UCSR0A & (1 << RXC0))) {}

	/* Get and return received data from buffer - p189 */
	return UDR0;
}
