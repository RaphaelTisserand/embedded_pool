#include "include.h"
#include "macros.h"

FT_ISR(USART_RX_vect_num) { uart_tx(swap_case(UDR0)); }

int main(void) {
	uart_init(MYUBRR);

	/* Complete Interrupt Enable - p201 */
	UCSR0B |= (1 << RXCIE0);

	sei(); // set Global Interrupt Enable - p20/25

	for (;;) {}

	return 0;
}
