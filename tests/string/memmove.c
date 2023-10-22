#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ft/string.h>

static void test_not_overlapping(void)
{
	volatile unsigned char a[512];
	volatile unsigned char b[512];

	for (size_t i = 0; i < sizeof(a); ++i) {
		a[i] = rand() % 255;
		b[i] = a[i] + 2;
	}

	assert(memcmp((void *)a, (void *)b, sizeof(a)));
	assert(b == ft_memmove((void *)b, (void *)a, sizeof(a)));
	assert(!memcmp((void *)a, (void *)b, sizeof(a)));
}

static void test_overlapping_left(void)
{
	unsigned char a[] = { 1, 2, 3, 4, 5, 6 };

	assert(a == ft_memmove(a, a + 2, 4));
	assert(a[0] == 3);
	assert(a[1] == 4);
	assert(a[2] == 5);
	assert(a[3] == 6);
	assert(a[4] == 5);
	assert(a[5] == 6);
}

static void test_overlapping_right(void)
{
	unsigned char a[] = { 1, 2, 3, 4, 5, 6 };

	assert((a + 2) == ft_memmove(a + 2, a, 4));
	assert(a[0] == 1);
	assert(a[1] == 2);
	assert(a[2] == 1);
	assert(a[3] == 2);
	assert(a[4] == 3);
	assert(a[5] == 4);
}

int main(void)
{
	test_not_overlapping();
	test_overlapping_left();
	test_overlapping_right();
	assert(NULL == ft_memmove(NULL, NULL, 0));
}
