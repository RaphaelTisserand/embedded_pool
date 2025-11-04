#include <avr/interrupt.h>
#include <avr/io.h>

void uart_tx(char c) {
	/* Wait for empty transmit buffer */
	while (!(UCSRnA & (1 << UDREn))) {}

	/* Put data into buffer, sends the data */
	UDRn = data;
}
