#include "include.h"

int main(void) {
	uart_init(MYUBRR);
	uart_printstr("Hello World!\n");

	for (;;) {}

	return 0;
}
