#include <avr/io.h>

int main(void) {
	DDRB = 1 << DDB1; // PB1 initialisation -> output mod

	OCR1A = 6250; // Set the flag

	TCCR1A |= (1 << COM1A1); // Clear OC1A when flag gets hit
	TCCR1A &= ~(1 << COM1A0);

	TCCR1B |= (1 << WGM12) | (1 << CS12); // Divide frequency by 256
	TCCR1B &= ~((1 << CS11) | (1 << CS10));

	for (;;) {} // Empty loop

	return 0;
}
