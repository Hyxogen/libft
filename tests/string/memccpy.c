#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ft/string.h>

void test1(void)
{
	unsigned char a[512], b[512];

	memset(a, 0xfe, sizeof(a));
	memset(b, 0xbe, sizeof(b));

	assert(memcmp(a, b, sizeof(a)));
	assert(NULL == ft_memccpy(b, a, 0x42, sizeof(a)));
	assert(!memcmp(a, b, sizeof(a)));
}

void test_cast(void)
{
	unsigned char a[512], b[512];

	memset(a, 0xfe, sizeof(a));
	memset(b, 0xbe, sizeof(b));

	assert(memcmp(a, b, sizeof(a)));
	assert(NULL == ft_memccpy(b, a, 0x142, sizeof(a)));
	assert(!memcmp(a, b, sizeof(a)));
}

void test2(unsigned offset)
{
	unsigned char a[512], b[512];

	memset(a, 0xfe, sizeof(a));
	memset(b, 0xbe, sizeof(b));

	a[offset] = 0x42;
	++offset;
	assert(memcmp(a, b, sizeof(a)));
	assert((b + offset) == ft_memccpy(b, a, 0x42, sizeof(a)));
	assert(!memcmp(a, b, offset));
	assert(memcmp(a + offset, b + offset, sizeof(a) - offset));
}

void test_zero(void *a, void *b)
{
	assert(NULL == ft_memccpy(a, b, 0xfe, 0));
}

int main(void)
{
	test1();
	test_cast();
	test2(0);
	test2(1);
	test2(231);
	test_zero(NULL, NULL);
	return 0;
}
