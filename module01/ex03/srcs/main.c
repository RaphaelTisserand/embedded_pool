#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB = 1 << DDB1; // Set PB1 to output mod - p100

	/* Prescaler divide Timer1 frequency by 256 (= 62500Hz) - p143 */
	TCCR1B |= (1 << CS12);
	TCCR1B &= ~((1 << CS11) | (1 << CS10));

	/* Set Fast PWM mod - p142 */
	TCCR1B |= (1 << WGM13) | (1 << WGM12);
	TCCR1A |= (1 << WGM11);
	TCCR1A &= ~(1 << WGM10);

	/* Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at BOTTOM (non-inverting
	 * mode) - p140 */
	TCCR1A |= (1 << COM1A1);
	TCCR1A &= ~(1 << COM1A0);

	/* p132 */
	ICR1 = 62500;
	OCR1A = 6250;

	uint8_t value = 1;

	for (;;) {
		_delay_ms(100);

		/* If SW1 is pressed - p100 */
		if (!(PIND & (1 << PD2))) {
			if (value < 10) {
				++value;
			}
			OCR1A = 6250 * value;
			/* Lock program while SW1 is pressed - p100 */
			while (!(PIND & (1 << PD2))) {}
			/* If SW2 is pressed - p100 */
		} else if (!(PIND & (1 << PD4))) {
			if (value > 1) {
				--value;
			}
			OCR1A = 6250 * value;
			/* Lock program while SW2 is pressed - p100 */
			while (!(PIND & (1 << PD4))) {}
		}
	}

	return 0;
}
