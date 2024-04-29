#ifndef FT_STDIO_H
#define FT_STDIO_H

__attribute__ ((format(printf, 1, 2))) int ft_printf(const char *fmt, ...);

__attribute__ ((format(printf, 2, 3))) int ft_dprintf(int fd, const char *fmt, ...);

#endif
