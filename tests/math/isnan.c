#include <ft/math.h>
#include <math.h>
#include <assert.h>

#define TEST_ONE(x) assert(isnan(x) == ft_isnan(x))

int main()
{
	TEST_ONE(0.0);
	TEST_ONE(0.0f);
	TEST_ONE(1.0f);
	TEST_ONE(42.0f);
	TEST_ONE(-42.0f);
	TEST_ONE(NAN);
	TEST_ONE(HUGE_VALF);
	TEST_ONE(HUGE_VAL);
	TEST_ONE(HUGE_VALL);
	return 0;
}
