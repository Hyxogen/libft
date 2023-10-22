#include <ft/string.h>

void *ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned char *d = dest;
	const unsigned char *s = src;

	while (n--)
		*d++ = *s++;
	return dest;
}

void *ft_mempcpy(void *restrict dest, const void *restrict src, size_t n)
{
	ft_memcpy(dest, src, n);
	return (unsigned char *)dest + n;
}

void *ft_memccpy(void *restrict dest, const void *restrict src, int c, size_t n)
{
	unsigned char *d = dest;
	const unsigned char *s = src;

	for (; n && (*d = *s) != (unsigned char)c; n--, s++, d++)
		;
	if (n)
		return d + 1;
	return NULL;
}

void *ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char *s = src;

	for (; n && *s != (unsigned char)c; n--, s++)
		;
	if (n)
		return (void *)s;
	return NULL;
}

int ft_memcmp(const void *lhs, const void *rhs, size_t n)
{
	const unsigned char *l = lhs;
	const unsigned char *r = rhs;

	for (; n && *l == *r; n--, l++, r++)
		;
	if (n)
		return (*l > *r) - (*l < *r);
	return 0;
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d = dest;
	const unsigned char *s = src;

	if (d <= s) {
		while (n--)
			*d++ = *s++;
	} else {
		while (n--)
			d[n] = s[n];
	}
	return dest;
}

void *ft_memset(void *dest, int c, size_t n)
{
	unsigned char *d = dest;

	while (n--)
		*d++ = (unsigned char)c;
	return dest;
}

char *ft_stpcpy(char *restrict dest, const char *restrict src)
{
	char *p = ft_mempcpy(dest, src, ft_strlen(src));
	*p = '\0';
	return p;
}

char *ft_strcpy(char *restrict dest, const char *restrict src)
{
	ft_stpcpy(dest, src);
	return dest;
}

size_t ft_strspn(const char *dest, const char *src)
{
	const char *tmp = dest;
	size_t src_len = ft_strlen(src);

	while (*tmp) {
		if (!ft_memchr(src, *tmp, src_len))
			break;
		++tmp;
	}
	return tmp - dest;
}

size_t ft_strcspn(const char *dest, const char *src)
{
	const char *tmp = dest;
	size_t src_len = ft_strlen(src);

	while (*tmp) {
		if (ft_memchr(src, *tmp, src_len))
			break;
		++tmp;
	}
	return tmp - dest;
}

size_t ft_strlen(const char *str)
{
	const char *tmp = str;

	while (*tmp)
		++tmp;
	return tmp - str;
}
