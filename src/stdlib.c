#include <ft/stdlib.h>
#include <ft/ctype.h>
#include <ft/strings.h>
#include <limits.h>
#include <errno.h>

static const unsigned char table[] = {
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  1,	2,  3,	4,  5,
	6,  7,	8,  9,	-1, -1, -1, -1, -1, -1, -1, 10, 11, 12, 13, 14, 15, 16,
	17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
	35, -1, -1, -1, -1, -1, -1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
	21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1,
};

static unsigned long long strtox(const char *restrict str,
				 char **restrict endptr, unsigned base,
				 unsigned long long lim)

{
	if (base > 36 || base == 1) {
		errno = EINVAL;
		return 0;
	}

	if (endptr)
		*endptr = (char *)str;

	int valid = 0;
	while (ft_isspace(*str))
		++str;

	int neg = 0;
	if (*str == '+' || *str == '-')
		neg = -(*str++ == '-');

	if (base == 16 && !ft_strncasecmp(str, "0x", 2))
		str += 2;
	if (!base) {
		if (!ft_strncasecmp(str, "0x", 2)) {
			base = 16;
			str += 2;
		} else if (*str == '0') {
			base = 8;
		} else {
			base = 10;
		}
	}

	unsigned long long res = 0;
	unsigned char val;
	int overflowed = 0;
	while ((val = table[(unsigned char)*str]) < base) {
		unsigned long long tmp = res * base;
		if (tmp / base != res)
			overflowed = 1;

		tmp += val;
		if (tmp < val)
			overflowed = 1;

		res = tmp;
		valid = 1;
		++str;
	}

	if (endptr && valid)
		*endptr = (char *)str;

	if (overflowed) {
		errno = ERANGE;
		res = lim;
		if (lim & 1)
			neg = 0;
	}

	if (res >= lim) {
		if (!(lim & 1) && !neg) {
			errno = ERANGE;
			res = lim - 1;
		} else if (res > lim) {
			errno = ERANGE;
			neg = 0;
			res = lim;
		}
	}
	return (res ^ neg) - neg;
}

long ft_strtol(const char *restrict str, char **restrict endptr, int base)
{
	return (long)strtox(str, endptr, base, (unsigned long long)LONG_MIN);
}
