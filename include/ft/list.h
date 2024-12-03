#ifndef FT_LIST_H
#define FT_LIST_H

#include <stdbool.h>

/* singly linked list */
struct ft_flist {
	void *_private;
	struct ft_flist *next;
};

struct ft_flist *ft_flist_new(void *data);
/* only destroys the link */
void ft_flist_free(struct ft_flist *link);
/* returns the next link */
void ft_flist_add_back(struct ft_flist **list, struct ft_flist *link);
struct ft_flist *ft_flist_push_back(struct ft_flist **list, void *data);
struct ft_flist *ft_flist_unlink(struct ft_flist *list, bool (*p)(const void*, const void *), const void *opaque);
void ft_flist_destroy(struct ft_flist *list, void (*del)(void*));

#endif
