#include <assert.h>
#include <string.h>
#include <ft/string.h>

#define TEST(dest, src) assert(ft_strspn(dest, src) == strspn(dest, src))

int main(void)
{
	TEST("Hello World!", "");
	TEST("Hello World!", "h");
	TEST("Hello World!", "H");
	TEST("Hello World!", "EH");
	TEST("Hello World!", "eH");
	TEST("Hello World!", "eH!");
	TEST("Hello World!",
	     "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
}
