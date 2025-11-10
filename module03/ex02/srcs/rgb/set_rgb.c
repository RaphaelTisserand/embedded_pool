#include "include.h"

void set_rgb(uint8_t r, uint8_t g, uint8_t b) {
	PORTD = (1 << PB3) | (1 << PB5) | (1 << PB6);
}
