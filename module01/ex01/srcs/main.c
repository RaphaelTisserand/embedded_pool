#include <avr/io.h>

int main(void) {
	DDRB = 1 << DDB1; // PB1 initialisation -> output mod

	OCR1A = 31250; // Set the flag

	TCCR1A &= ~(1 << COM1A1);
	TCCR1A |= (1 << COM1A0); // Toggle OC1A when flag gets hit

	TCCR1B |= (1 << WGM12) | (1 << CS12);
	TCCR1B &= ~((1 << CS11) | (1 << CS10));

	for (;;) {} // Empty loop

	return 0;
}
