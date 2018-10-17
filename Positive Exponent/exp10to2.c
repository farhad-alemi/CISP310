#include "number.h"
#include "exp10to2.h"

void exp10ToExp2(struct Number *pn)
{
	// in this function, convert the number pointed to b
	// pn from a base-10 mantissa and exponent to a base-2
	// mantissa and exponent
	// divide into two main cases: when exp10 > 0, and when
	// exp10 < 0
    while (pn->exp10 > 0)
    {
        while ((pn->mantissa <= ((UINT64_MAX - 1) / 10)) && pn->exp10 > 0)
        {
            pn->mantissa *= 10;
            pn->exp10--;
        }
        while ((pn->mantissa > (UINT64_MAX / 10)) && pn->exp10 > 0)
        {
            pn->mantissa = ((pn->mantissa + 1) / 2);
            pn->exp2++;
        }
    }
}
