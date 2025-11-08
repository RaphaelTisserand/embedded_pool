#include "include.h"

int main(void) {
	uart_init(MYUBRR);

	for (;;) {
		uart_tx(uart_rx());
	}

	return 0;
}
