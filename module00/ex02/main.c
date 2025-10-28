#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB = 1 << DDB0;

	for (;;) { PORTB = !(PIND & (1 << PD2)); }
}
