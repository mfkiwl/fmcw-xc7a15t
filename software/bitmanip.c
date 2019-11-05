#include "bitmanip.h"

uint64_t add_byte_to_word(uint64_t w, int l, unsigned char b)
{
	uint64_t bshift;
	bshift = b << l; /* TODO ub?? */
	return w | bshift;
}

int64_t subw_val(uint64_t w, int l, int n, unsigned char s)
{
	uint64_t mask;
	uint64_t lower_mask, upper_mask;
	uint64_t extract;
	int neg;

	mask = -1;
	lower_mask = mask >> l;
	upper_mask = mask << (l + n);
	mask = ~(upper_mask | lower_mask);

	extract = (w & mask) >> l;

	neg = extract & (1 << n);

	if (s && neg)
		return extract - (2 << n);

	return extract;
}