#include <avr/io.h>
#include <util/delay.h>

void	print_value(uint8_t value) {
	PORTB = ((value << 1) & 0b00010000) | (value & 0b00000111);
}

int	main(void) {
	DDRB = (1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB4);

	uint8_t	value = 0;

	for (;;) {
		print_value(value);
		if (!(PIND & (1 << PD2))) {
			if (value < 15) {
				++value;
			}
			print_value(value);
			while (!(PIND & (1 << PD2))) {}
		} else if (!(PIND & (1 << PD4))) {
			if (value > 0) {
				--value;
			}
			print_value(value);
			while (!(PIND & (1 << PD4))) {}
		}

		_delay_ms(100);
	}
}
