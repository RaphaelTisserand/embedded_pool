#include "include.h"

void uart_printstr(const char *str) {
	for (int i = 0; str[i]; ++i) {
		uart_tx(str[i]);
	}
}
