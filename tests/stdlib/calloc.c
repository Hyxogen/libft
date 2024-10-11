#include <ft/stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

static int is_zeroed(const void *p, size_t nbytes)
{
	const unsigned char *c = p;

	while (nbytes--) {
		if (*c)
			return 0;
	}
	return 1;
}

int main(void)
{
	void *p = ft_calloc(1, 20);
	assert(is_zeroed(p, 20));

	free(p);

	p = ft_calloc(60, 1);
	assert(is_zeroed(p, 60));

	free(p);

	p = ft_calloc(SIZE_MAX / 128, 256);
	assert(!p);
	assert(errno == ENOMEM);
}
