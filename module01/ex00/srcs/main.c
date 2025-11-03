#include <avr/io.h>

int main(void) {
	DDRB = 1 << PB1; // Set PB1 to output mod - p100

	for (;;) {
		for (uint8_t i = 0; i < 255; ++i) {
			for (uint8_t i = 0; i < 255; ++i) {
				for (uint8_t i = 0; i < 10; ++i) {
					/* Takes a lot of time to run */
				}
			}
		}

		PORTB ^= 1 << PB1; // Toggle PB1 - p100
	}

	return 0;
}
