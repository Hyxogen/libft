#ifndef FT_STDIO_H
#define FT_STDIO_H

#include <stddef.h>

__attribute__ ((format(printf, 1, 2))) int ft_printf(const char *fmt, ...);
__attribute__ ((format(printf, 2, 3))) int ft_dprintf(int fd, const char *fmt, ...);
__attribute__ ((format(printf, 3, 4))) int ft_snprintf(char *str, size_t size, const char *fmt, ...);

#endif
