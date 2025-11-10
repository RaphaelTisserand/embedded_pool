#pragma once

#define FT_ISR(vect)                                                           \
	__attribute__((signal, used, externally_visible)) void __vector_##vect(void)
