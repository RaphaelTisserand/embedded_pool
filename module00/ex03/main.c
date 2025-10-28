#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB = 1 << DDB0;

	for (;;) {
		_delay_ms(100);
		if (!(PIND & (1 << PD2))) {
			PINB = (1 << PB0);
			while (!(PIND & (1 << PD2))) {}
		}
	}
}
