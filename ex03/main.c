#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	PORTB = 0;
	_Bool	kp;

	for (;;) {
		_delay_ms(100);
		if (!(PIND & (1 << PD2)) && !kp) {
			kp = 1;
			PINB = (1 << PB0);
		} else if (PIND & (1 << PD2) && kp) {
			kp = 0;
		}
	}
}
