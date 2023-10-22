#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ft/string.h>

void test(void)
{
	volatile unsigned char a[512];
	volatile unsigned char b[512];

	for (size_t i = 0; i < sizeof(a); ++i) {
		a[i] = rand() % 255;
		b[i] = a[i] + 2;
	}

	assert(memcmp((void *)a, (void *)b, sizeof(a)));
	assert((b + sizeof(a) == ft_mempcpy((void *)b, (void *)a, sizeof(a))));
	assert(!memcmp((void *)a, (void *)b, sizeof(a)));
}

void test_zero(void)
{
	volatile unsigned char a[] = { 1, 2, 3 };
	assert(a == ft_mempcpy((void *)a, (void *)a, 0));
	assert(a[0] == 1);
	assert(a[1] == 2);
	assert(a[2] == 3);
}

int main(void)
{
	test();
	test_zero();
}
