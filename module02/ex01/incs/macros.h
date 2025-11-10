#pragma once

#include <avr/interrupt.h>
#include <avr/io.h>

#define FT_ISR(vect)                                                           \
	__attribute__((signal, used, externally_visible)) void __vector_##vect(void)
