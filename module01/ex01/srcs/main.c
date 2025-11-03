#include <avr/io.h>

int main(void) {
	DDRB = 1 << DDB1; // Set PB1 to output mod - p100

	/* Prescaler divide Timer1 frequency by 256 (= 62500Hz) - p143 */
	TCCR1B |= (1 << WGM12) | (1 << CS12);
	TCCR1B &= ~((1 << CS11) | (1 << CS10));

	/* Toggle OC1A/OC1B on Compare Match. - p140 */
	TCCR1A &= ~(1 << COM1A1);
	TCCR1A |= (1 << COM1A0);

	OCR1A = 31250; // p131

	for (;;) {}

	return 0;
}
