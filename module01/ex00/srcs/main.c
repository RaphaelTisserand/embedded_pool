#include <avr/io.h>

int	main(void) {
	DDRB = 1 << PB1; // PB1 initialisation -> output mod

	for (;;) {
		for (uint8_t i = 0; i < 255; ++i) {
			for (uint8_t i = 0; i < 255; ++i) {
				for (uint8_t i = 0; i < 10; ++i) {
					/* Takes a lot of time to run */
				}
			}
		}
		PORTB ^= 1 << PB1; // Turns on/off PB1
	}

	return 0;
}
