#include <ft/strings.h>
#include <ft/ctype.h>

int ft_strcasecmp(const char *s1, const char *s2)
{
	const unsigned char *p1 = (const unsigned char *)s1;
	const unsigned char *p2 = (const unsigned char *)s2;

	int val = 0;
	while ((val = (ft_tolower(*p1) - ft_tolower(*p2))) == 0 && *p1) {
		++p1;
		++p2;
	}
	return val;
}

int ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *p1 = (const unsigned char *)s1;
	const unsigned char *p2 = (const unsigned char *)s2;

	int val = 0;
	while (n-- && (val = (ft_tolower(*p1) - ft_tolower(*p2))) == 0 && *p1) {
		++p1;
		++p2;
	}
	return val;
}
