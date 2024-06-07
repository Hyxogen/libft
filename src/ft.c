#include <ft/ft.h>
#include <ft/stdio.h>
#include <ft/string.h>
#include <ft/strings.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_strjoin(char const *s1, char const *s2)
{
	char *ret;
	size_t s1_len;
	size_t s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = malloc(s1_len + s2_len + 1);
	if (!ret)
		return NULL;
	ft_memcpy(ret, s1, s1_len);
	ft_memcpy(ret + s1_len, s2, s2_len + 1);
	return ret;
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	if (!*lst) {
		*lst = new;
		return;
	}
	last = *lst;
	while (last) {
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = new;
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next;

	while (*lst) {
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void ft_lstiter(t_list *lst, void (*func)(void *))
{
	while (lst) {
		func(lst->content);
		lst = lst->next;
	}
}

t_list *ft_lstlast(t_list *lst)
{
	while (lst) {
		if (!lst->next)
			break;
		lst = lst->next;
	}
	return (lst);
}

t_list *ft_lstmap(t_list *lst, void *(*func)(void *), void (*del)(void *))
{
	t_list *ret;
	void *temp_data;
	void *temp_element;

	ret = 0;
	while (lst) {
		temp_data = func(lst->content);
		temp_element = ft_lstnew(temp_data);
		if (!temp_element) {
			ft_lstclear(&ret, del);
			return (0);
		}
		ft_lstadd_back(&ret, temp_element);
		lst = lst->next;
	}
	return (ret);
}

t_list *ft_lstnew(void *content)
{
	t_list *ret;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (0);
	ret->content = content;
	ret->next = 0;
	return (ret);
}

int ft_lstsize(t_list *lst)
{
	int ret;

	ret = 0;
	while (lst) {
		ret++;
		lst = lst->next;
	}
	return (ret);
}

void ft_lstforeach(const t_list *lst, void (*f)(void *, void *), void *opaque)
{
	while (lst) {
		f(lst->content, opaque);
		lst = lst->next;
	}
}

static size_t get_size(const char *str, char c)
{
	if (!*str)
		return (1);
	while (*str && *str == c)
		str++;
	while (*str && *str != c)
		str++;
	return (get_size(str, c) + 1);
}

static void clear_array(char **array)
{
	char **start;

	start = array;
	while (*array) {
		free(*array);
		array++;
	}
	free(start);
}

static int fill_array(char **out, char *dup, const char *delim)
{
	char *token_start;

	while (1) {
		token_start = ft_strsep(&dup, delim);
		if (token_start == dup)
			continue;
		if (!dup && *token_start) {
			*out = ft_strdup(token_start);
			if (!*out)
				return (0);
			break;
		} else if (!dup)
			break;
		else if (dup - token_start > 1) {
			*out = ft_strdup(token_start);
			if (!*out)
				return (0);
			out++;
		}
	}
	return (1);
}

char **ft_split(char const *str, char c)
{
	char delim[2];
	char **ret;
	char *dup;
	size_t size;

	delim[0] = c;
	delim[1] = '\0';
	size = get_size(str, c);
	if (!size)
		return (0);
	ret = malloc(sizeof(char *) * size);
	if (!ret)
		return (0);
	ft_memset(ret, 0, sizeof(char *) * size);
	dup = ft_strdup(str);
	if (!dup || !fill_array(ret, dup, delim)) {
		clear_array(ret);
		free(dup);
		return (0);
	}
	free(dup);
	return (ret);
}

int ft_putchar_fd(char ch, int fd) { return write(fd, &ch, 1); }

int ft_putstr_fd(const char *str, int fd)
{
	return write(fd, str, ft_strlen(str));
}

char *ft_itoa(int num)
{
	char buf[16];

	ft_snprintf(buf, sizeof(buf), "%i", num);
	return ft_strdup(buf);
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstlen;
	size_t srclen;
	size_t len;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (!dstsize || dstlen > dstsize)
		return (dstsize + srclen);
	if (srclen >= (dstsize - dstlen))
		len = dstsize - dstlen - 1;
	else
		len = srclen;
	while (*dst) {
		dst++;
		dstsize--;
		if (!dstsize)
			return (dstlen + srclen);
	}
	ft_strlcpy(dst, src, len + 1);
	return (dstlen + srclen);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t srclen;
	size_t len;

	srclen = ft_strlen(src);
	if (!dstsize)
		return (srclen);
	if (srclen >= dstsize)
		len = dstsize - 1;
	else
		len = srclen;
	while (len) {
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	*dst = '\0';
	return (srclen);
}
