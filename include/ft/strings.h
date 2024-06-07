#ifndef FT_STRINGS_H
#define FT_STRINGS_H

#include <stddef.h>

int ft_strcasecmp(const char *s1, const char *s2);
int ft_strncasecmp(const char *s1, const char *s2, size_t n);
__attribute__ ((deprecated)) void ft_bzero(void *s, size_t n);

#endif
