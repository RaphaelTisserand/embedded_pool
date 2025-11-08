#include "include.h"

void uart_tx(char data) {
	/* Wait for empty transmit buffer - p186/200 */
	while (!(UCSR0A & (1 << UDRE0))) {}

	/* Put data into buffer, sends the data - p186/200 */
	UDR0 = data;
}
