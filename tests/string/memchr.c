#include <assert.h>
#include <string.h>
#include <ft/string.h>

void test_no_match(void)
{
	unsigned char a[512];

	memset(a, 0xfe, sizeof(a));
	assert(NULL == ft_memchr(a, 0x42, sizeof(a)));
}

void test_simple(unsigned offset)
{
	unsigned char a[512], b[512];

	memset(a, 0xfe, sizeof(a));
	assert(offset < sizeof(a));
	a[offset] = 0x42;
	memcpy(b, a, sizeof(a));
	assert((a + offset) == ft_memchr(a, 0x42, sizeof(a)));
	assert((a + offset) ==
	       ft_memchr(a, 0x142,
			 sizeof(a))); // check if c is cast to unsigned char
	assert(!memcmp(a, b, sizeof(a)));
}

void test_zero(const void *p)
{
	assert(NULL == ft_memchr(p, 0x42, 0));
}

int main(void)
{
	test_no_match();
	test_simple(0);
	test_simple(1);
	test_simple(20);
	test_zero(NULL);
}
