#include <ft/stdlib.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

static void test_one(const char *str, int base)
{
	char *endptr1, *endptr2;
	endptr1 = endptr2 = NULL;

	int errno1, errno2;

	errno = 0;
	unsigned long long res1 = strtoull(str, &endptr1, base);
	errno1 = errno;

	errno = 0;
	unsigned long long res2 = ft_strtoull(str, &endptr2, base);
	errno2 = errno;

	if (res1 != res2 || endptr1 != endptr2 || errno1 != errno2) {
		fprintf(stderr, "for str=\"%s\" base=%i:\n", str, base);
		fprintf(stderr, "expected result: %llu got: %llu\n", res1, res2);
		fprintf(stderr, "expected endptr: %p got: %p begin: %p\n",
			(void *)endptr1, (void *)endptr2, (void *)str);
		fprintf(stderr, "expected errno: %i(%s) got: %i(%s)\n", errno1,
			strerror(errno1), errno2, strerror(errno2));
		assert(res1 == res2);
		assert(endptr1 == endptr2);
		assert(errno1 == errno2);
		assert(0);
	}
}

int main(void)
{
	test_one("", 10);
	test_one("1", 10);
	test_one("0", 10);
	test_one("-", 10);
	test_one("-1", 10);
	test_one("-0", 10);
	test_one("+", 10);
	test_one("+1", 10);
	test_one("+0", 10);
	test_one(" \n\t  -1", 10);
	test_one(" \n\t  -0", 10);
	test_one(" \n\t  +", 10);
	test_one(" \n\t  +1", 10);
	test_one(" \n\t  +0", 10);
	test_one("4294967296", 10);
	test_one("ffffffff", 16);
	test_one("9223372036854775807", 10);
	test_one("9223372036854775808", 10);
	test_one("-9223372036854775808", 10);
	test_one("18446744073709551615", 10);
	test_one("-18446744073709551616", 10);
	test_one("-0xf", 0);
	test_one("-01", 0);
	test_one("-0xffff", 0);
	test_one("-01342", 0);
	test_one("zDfe", 36);
	test_one("CoOL", 36);
	test_one("alskasdjkfjlaskfjsdkfljsfkajsdkfj", 36);
	test_one("alskasdjkfjlaskfjsdkfljsfkajsdkfj", 0);
	test_one("--1", 0);
	test_one("- 1", 0);
}
