#include <avr/io.h>

int main () {
	DDRB |= (1 << PRB0);

	PORTB = 1;

	return 0;
}
