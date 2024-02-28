#include <ft/math.h>
#include <math.h>
#include <assert.h>

static int one_or_zero(int i)
{
	if (i)
		return 1;
	return 0;
}

#define TEST_ONE(x) \
	assert(one_or_zero(signbit(x)) == one_or_zero(ft_signbit(x)))

int main()
{
	TEST_ONE(0.0);
	TEST_ONE(0.0f);
	TEST_ONE(-0.0);
	TEST_ONE(-0.0f);
	TEST_ONE(1.0f);
	TEST_ONE(42.0f);
	TEST_ONE(-42.0f);
	TEST_ONE(NAN);
	TEST_ONE(HUGE_VALF);
	TEST_ONE(HUGE_VAL);
}
