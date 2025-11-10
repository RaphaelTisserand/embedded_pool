#include "include.h"
#include "macros.h"

int main(void) {
	DDRD = (1 << DDD3) | (1 << DDD5) | (1 << DDD6);

	for (;;) {
		PORTD = (1 << PB3);
		_delay_ms(1000);
		PORTD = (1 << PB5);
		_delay_ms(1000);
		PORTD = (1 << PB6);
		_delay_ms(1000);
	}

	return 0;
}
