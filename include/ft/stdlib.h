#ifndef FT_STDLIB_H
#define FT_STDLIB_H

#include <stddef.h>

void ft_srand(unsigned s);
int ft_rand(void);

long ft_strtol(const char *restrict nptr, char **restrict endptr, int base);
unsigned long long ft_strtoull(const char *restrict nptr, char **restrict endptr, int base);
long ft_atol(const char *str);

char *ft_getenv(const char *name);

void ft_qsort(void *ptr, size_t count, size_t size,
	      int (*comp)(const void *, const void *));

void *ft_calloc(size_t nmemb, size_t size);

#endif
