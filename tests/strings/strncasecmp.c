#include <ft/strings.h>
#include <strings.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

static int sign_or_zero(int i)
{
	if (i < 0)
		return -1;
	if (i > 0)
		return 1;
	return 0;
}

#define TEST_ONE(a, b)                                                      \
	do {                                                                \
		size_t __l = strlen(a) > strlen(b) ? strlen(a) : strlen(b); \
		assert(sign_or_zero(strncasecmp(a, b, INT_MAX)) ==              \
		       sign_or_zero(ft_strncasecmp(a, b, INT_MAX)));            \
		for (size_t __i = 0; __i < __l; ++__i) {                    \
			assert(sign_or_zero(strncasecmp(a, b, __i)) ==          \
			       sign_or_zero(ft_strncasecmp(a, b, __i)));        \
			assert(sign_or_zero(strncasecmp(b, a, __i)) ==          \
			       sign_or_zero(ft_strncasecmp(b, a, __i)));        \
		}                                                           \
	} while (0)

static char *decay(char arr[]) {
	return arr;
}

int main()
{
	TEST_ONE("", "");
	TEST_ONE("a", "a");
	TEST_ONE("A", "A");
	TEST_ONE("a", "A");
	TEST_ONE("HaLLo DaaR",  "hallo daar");
	TEST_ONE("HaLLo DaaR",  "HaLLo daar");
	TEST_ONE("HaLLo DaaR",  "hallo niks");
	TEST_ONE("HaLLo DaaR",  "");

	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 256; ++j) {
			char a[] = { i, 0 };
			char b[] = { j, 0 };
			TEST_ONE(decay(a), decay(b));
		}
	}
}
