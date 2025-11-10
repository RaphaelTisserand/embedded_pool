#include "include.h"

void init_rgb() { DDRD = (1 << DDD3) | (1 << DDD5) | (1 << DDD6); }
