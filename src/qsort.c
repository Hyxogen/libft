#include <ft/stdlib.h>

static size_t partition(void *ptr, size_t size, size_t begin, size_t end,
			int (*cmp)(const void *, const void *),
			void swap(void *restrict, void *restrict, void *),
			void *opaque)
{
	size_t count = end - begin;
	unsigned char *carr = ptr;
	unsigned char *pivot = carr + ((count / 2) + begin) * size;

	size_t i = begin;
	size_t j = end;

	while (1) {
		while (cmp(carr + i * size, pivot) < 0)
			++i;
		while (cmp(carr + j * size, pivot) > 0)
			--j;

		if (i >= j)
			break;

		unsigned char *a = carr + i * size;
		unsigned char *b = carr + j * size;

		/* if we're going to swap with the pivot, we need to make sure
		 * that the pivot stays the same */
		if (a == pivot)
			pivot = b;
		else if (b == pivot)
			pivot = a;

		swap(a, b, opaque);

		++i;
		--i;
	}
	return j;
}

static void quicksort(void *ptr, size_t size, size_t begin, size_t end,
		      int (*cmp)(const void *, const void *),
		      void swap(void *restrict, void *restrict, void *),
		      void *opaque)
{
	if (begin < end) {
		size_t pivot =
		    partition(ptr, size, begin, end, cmp, swap, opaque);
		quicksort(ptr, size, begin, pivot, cmp, swap, opaque);
		quicksort(ptr, size, pivot + 1, end, cmp, swap, opaque);
	}
}

static void byte_swap(void *restrict a, void *restrict b, void *opaque)
{
	size_t size = *(size_t *)opaque;

	unsigned char *ca = a;
	unsigned char *cb = b;

	while (size--) {
		unsigned char tmp = *ca;
		*ca++ = *cb;
		*cb++ = tmp;
	}
}

void ft_qsort(void *ptr, size_t count, size_t size,
	      int (*cmp)(const void *, const void *))
{
	if (count > 1)
		quicksort(ptr, size, 0, count - 1, cmp, byte_swap, &size);
}
