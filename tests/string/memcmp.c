#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ft/string.h>

static void test_equal(void)
{
	unsigned char a[512], b[512];

	for (unsigned i = 0; i < sizeof(a); ++i) {
		a[i] = b[i] = rand();
	}
	assert(!ft_memcmp(a, b, sizeof(a)));
}

static void test_nequal(void)
{
	unsigned char a[512], b[512];

	for (unsigned i = 0; i < sizeof(a); ++i) {
		a[i] = b[i] = rand();
	}
	a[20] = 0x0f;
	b[20] = 0xfe;
	assert(ft_memcmp(a, b, sizeof(a)) < 0);
	assert(ft_memcmp(b, a, sizeof(a)) > 0);
}

int main()
{
	test_equal();
	test_nequal();
}
