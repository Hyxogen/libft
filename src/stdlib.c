#include <errno.h>
#include <ft/ctype.h>
#include <ft/stdlib.h>
#include <ft/string.h>
#include <ft/strings.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

static const unsigned char table[] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,	1,  2,	3,  4,	5,  6,	7,  8,
    9,	-1, -1, -1, -1, -1, -1, -1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, -1, -1, -1, -1,
    -1, -1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 33, 34, 35, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1,
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

unsigned long long ft_strtoull(const char *restrict str, char **restrict endptr, int base)
{
	return strtox(str, endptr, base, ULLONG_MAX);
}

long ft_atol(const char *str) { return ft_strtol(str, NULL, 10); }

static uint64_t seed = 1;

void ft_srand(unsigned s)
{
	if (!s)
		seed = 1;
	seed = s;
}

int ft_rand(void)
{
	seed ^= seed << 13;
	seed ^= seed >> 7;
	seed ^= seed << 17;
	return seed % RAND_MAX;
}

extern char **environ;

char *ft_getenv(const char *name)
{
	if (environ) {
		size_t len = ft_strlen(name);

		for (char **env = environ; *env; ++env) {
			if (!ft_strncmp(name, *env, len) && (*env)[len] == '=')
				return &(*env)[len + 1];
		}
	}
	return NULL;
}

void *ft_calloc(size_t nmemb, size_t size)
{
	size_t nbytes = nmemb * size;

	if (size && (nbytes / size) != nmemb) {
		errno = ENOMEM;
		return NULL; /* would overflow */
	}

	void *p = malloc(nbytes);
	return ft_memset(p, 0, nbytes);
}
