#include <ft/strings.h>
#include <strings.h>
#include <assert.h>

static int sign_or_zero(int i)
{
	if (i < 0)
		return -1;
	if (i > 0)
		return 1;
	return 0;
}

#define TEST_ONE(a, b)                                     \
	do {                                               \
		assert(sign_or_zero(strcasecmp(a, b)) ==   \
		       sign_or_zero(ft_strcasecmp(a, b))); \
		assert(sign_or_zero(strcasecmp(b, a)) ==   \
		       sign_or_zero(ft_strcasecmp(b, a))); \
	} while (0)

int main()
{
	TEST_ONE("", "");
	TEST_ONE("a", "a");
	TEST_ONE("A", "A");
	TEST_ONE("a", "A");
	TEST_ONE("HaLLo DaaR",  "hallo daar");
	TEST_ONE("HaLLo DaaR",  "hallo niks");

	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 256; ++j) {
			char a[] = { i, 0 };
			char b[] = { j, 0 };
			TEST_ONE(a, b);
		}
	}
}
