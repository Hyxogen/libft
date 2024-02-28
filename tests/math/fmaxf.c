#include <ft/math.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

union ieee754f {
	float f;
	uint32_t i;
};

#define TEST_ONE(x, y)                                                      \
	do {                                                                \
		union ieee754f __a = { fmaxf(x, y) };                       \
		union ieee754f __b = { ft_fmaxf(x, y) };                    \
		if (__a.i != __b.i) {                                       \
			fprintf(stderr,                                     \
				"fmaxf(%x, %x) expected: 0x%x got: 0x%x\n", \
				__a.i, __b.i, __a.i, __b.i);                  \
			assert(0);                                          \
		}                                                           \
	} while (0)

#define TEST_BOTH(x, y)         \
	do {                    \
		TEST_ONE(x, y); \
		TEST_ONE(y, x); \
	} while (0)

static float randf(void)
{
	return (float)rand()/(float)RAND_MAX;
}

int main(void)
{
	TEST_BOTH(0.0f, 0.0f);
	TEST_BOTH(-0.0f, 0.0f);
	TEST_BOTH(1.0f, 0.0f);
	TEST_BOTH(1.0f, -0.0f);
	TEST_BOTH(-1.0f, 0.0f);
	TEST_BOTH(-42.0f, -42.0f);
	TEST_BOTH(NAN, 0.0f);
	TEST_BOTH(NAN, NAN);
	TEST_BOTH(HUGE_VALF, 42.0f);
	TEST_BOTH(HUGE_VALF, -42.0f);
	TEST_BOTH(-HUGE_VALF, 42.0f);

	for (int i = 0; i < 100; ++i) {
		float x = randf();
		float y = randf();
		TEST_BOTH(x, y);
	}
}
