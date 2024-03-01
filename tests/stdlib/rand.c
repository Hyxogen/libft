#include <ft/stdlib.h>
#include <assert.h>

int main(void)
{
	int a[128];

	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
		a[i] = ft_rand();
	ft_srand(1);
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
		assert(a[i] == ft_rand());
}
