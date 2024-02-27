#ifndef FT_STRING_H
#define FT_STRING_H

#include <stddef.h>

void *ft_memccpy(void *restrict, const void *restrict, int, size_t);
void *ft_mempcpy(void *restrict dest, const void *restrict src, size_t n);
void *ft_memchr(const void *, int, size_t);
int ft_memcmp(const void *, const void *, size_t);
void *ft_memcpy(void *restrict, const void *restrict, size_t);
void *ft_memmove(void *, const void *, size_t);
void *ft_memset(void *, int, size_t);
char *ft_stpcpy(char *restrict, const char *restrict);
char *ft_stpncpy(char *restrict, const char *restrict, size_t);
char *ft_strcat(char *restrict, const char *restrict);
char *ft_strchr(const char *, int);
int ft_strcmp(const char *, const char *);
int ft_strcoll(const char *, const char *);
char *ft_stpcpy(char *restrict dst, const char *restrict src);
char *ft_strcpy(char *restrict, const char *restrict);
size_t ft_strcspn(const char *, const char *);
char *ft_strdup(const char *);
char *ft_strndup(const char *, size_t);
char *ft_strerror(int);
int ft_strerror_r(int, char *, size_t);
size_t ft_strlen(const char *);
char *ft_strncat(char *restrict, const char *restrict, size_t);
int ft_strncmp(const char *, const char *, size_t);
char *ft_strncpy(char *restrict, const char *restrict, size_t);
size_t ft_strnlen(const char *, size_t);
char *ft_strpbrk(const char *, const char *);
char *ft_strrchr(const char *, int);
char *ft_strsignal(int);
size_t ft_strspn(const char *, const char *);
char *ft_strstr(const char *, const char *);
char *ft_strtok(char *restrict, const char *restrict);
char *ft_strtok_r(char *restrict, const char *restrict, char **restrict);
size_t ft_strxfrm(char *restrict, const char *restrict, size_t);

#endif
