#include "include.h"
#include "macros.h"

FT_ISR(TIMER1_COMPA_vect) { uart_printstr("Hello World!\n\r"); }

int main(void) {
	uart_init(MYUBRR);

	/* Set CTC mod - p141*/
	TCCR1B |= (1 << WGM12);

	/* Prescaler divide Timer1 frequency by 1024 (= 15625Hz) - p143 */
	TCCR1B |= (1 << CS12) | (1 << CS10);
	TCCR1B &= ~(1 << CS11);

	OCR1A = 31250; // p131

	TIMSK1 = (1 << OCIE1A);

	sei(); // set Global Interrupt Enable - p20/25

	for (;;) {}

	return 0;
}
