#include <assert.h>
#include <string.h>
#include <ft/string.h>

void test(const char *str)
{
	assert(ft_strlen(str) == strlen(str));
}

int main(void)
{
	test("");
	test("Hello World");
}
