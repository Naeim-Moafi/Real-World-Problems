#include "gcd.h"


unsigned int solution::gcd(unsigned const a, unsigned const b)
{
	return b == 0 ? a : gcd(b, a % b);
}

