#include <assert.h>
#include <string.h>
#include <ft/string.h>
#include <stdlib.h>

static void test(const char *str)
{
	size_t len = strlen(str);
	char *a = malloc(len + 1);
	char *b = malloc(len + 1);

	assert((a + len) == ft_stpcpy(a, str));
	stpcpy(b, str);
	assert(!strcmp(a, b));
}

int main()
{
	test("");
	test("Hello World");
}
