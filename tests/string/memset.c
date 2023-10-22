#include <assert.h>
#include <string.h>
#include <ft/string.h>

static void test_normal()
{
	unsigned char a[512], b[512];

	memset(a, 0xfe, sizeof(a));
	assert(b == ft_memset(b, 0xfe, sizeof(a)));
	assert(!memcmp(a, b, sizeof(a)));
}

static void test_cast()
{
	unsigned char a[512], b[512];

	memset(a, 0xabfe, sizeof(a));
	assert(b == ft_memset(b, 0xfe, sizeof(a)));
	assert(!memcmp(a, b, sizeof(a)));
}

int main(void)
{
	test_normal();
	test_cast();
}
