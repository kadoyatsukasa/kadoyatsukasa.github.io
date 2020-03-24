#include "chapter06.h"


//6.3
uint64_t fact(uint64_t val) {
	uint64_t ret;

	for (ret = 1; val > 1; val--)
		ret *= val;

	return ret;
}

