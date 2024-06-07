#ifndef FT_H
#define FT_H

#include <stddef.h>

typedef struct s_list {
	void *content;
	struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstiter(t_list *lst, void (*func)(void *));
t_list *ft_lstmap(t_list *lst, void *(*func)(void *), void (*del)(void *));
void ft_lstforeach(const t_list *lst, void (*f)(void *, void *), void *opaque);

char *ft_strjoin(const char *s1, const char *s2);
char **ft_split(char const *str, char c);

int ft_putchar_fd(char ch, int fd);
int ft_putstr_fd(const char *str, int fd);

char *ft_itoa(int num);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
