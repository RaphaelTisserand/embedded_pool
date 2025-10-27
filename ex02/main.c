#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	PORTB = 0;

	for (;;) { PORTB = !(PIND & (1 << PD2)); }
}
