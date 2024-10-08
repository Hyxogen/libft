#include <assert.h>
#include <ft/stdlib.h>
#include <stdlib.h>
#include <string.h>

static void test_one(void *arr, size_t count, size_t size,
		     int (*cmp)(const void *, const void *))
{
	assert(count > 0 && size > 0);

	void *dup = calloc(count, size);
	assert(dup);

	memcpy(dup, arr, count * size);

	ft_qsort(arr, count, size, cmp);
	qsort(dup, count, size, cmp);

	assert(!memcmp(arr, dup, size * count));

	free(dup);
}

static int cmp_int(const void *a, const void *b)
{
	int ia = *(const int *)a;
	int ib = *(const int *)b;

	return (ia > ib) - (ia < ib);
}

#define TEST_ONE(arr, cmp)                                                     \
	test_one((arr), sizeof((arr)) / sizeof((arr)[0]), sizeof((arr)[0]), cmp)

int main(void)
{
	ft_qsort(NULL, 0, 0, NULL);

	{
		int arr[] = {1};
		TEST_ONE(arr, cmp_int);
	}
	{
		int arr[] = {1, 2};
		TEST_ONE(arr, cmp_int);
	}
	{
		int arr[] = {2, 1};
		TEST_ONE(arr, cmp_int);
	}
	{
		int arr[] = {2, 1, 3};
		TEST_ONE(arr, cmp_int);
	}
	{
		int arr[] = {1, 2, 3};
		TEST_ONE(arr, cmp_int);
	}
	{
		int arr[500];

		for (int try = 0; try < 20; ++try) {
			for (unsigned i = 0; i < sizeof(arr) / sizeof(arr[0]);
			     ++i) {
				arr[i] = rand();
			}

			TEST_ONE(arr, cmp_int);
		}
	}
}
