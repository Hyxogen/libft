#include <ft/ctype.h>

int ft_isalnum(int c) { return ft_isalpha(c) || ft_isdigit(c); }

int ft_isalpha(int c) { return ft_isupper(c) || ft_islower(c); }

int ft_iscntrl(int c) { return (unsigned)c < 0x20 || c == 0x7f; }

int ft_isdigit(int c) { return (unsigned)c - '0' < 10; }

int ft_isgraph(int c) { return (unsigned)c - 0x21 < 0x5e; }

int ft_islower(int c) { return (unsigned)c - 'a' < 26; }

int ft_isprint(int c) { return (unsigned)c - 0x20 < 0x5f; }

int ft_ispunct(int c) { return ft_isgraph(c) && !ft_isalnum(c); }

int ft_isspace(int c) { return c == ' ' || (unsigned)c - '\t' < 5; }

int ft_isupper(int c) { return (unsigned)c - 'A' < 26; }

int ft_isxdigit(int c) { return ft_isdigit(c) || ((unsigned)c | 32) - 'a' < 6; }

int ft_isascii(int c) { return !(c & ~0x7f); }

int ft_isblank(int c) { return c == ' ' || c == '\t'; }

int ft_toupper(int c)
{
	if (ft_islower(c))
		return c & 0x5f;
	return c;
}

int ft_tolower(int c)
{
	if (ft_isupper(c))
		return c | 0x20;
	return c;
}
