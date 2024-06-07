#include <assert.h>
#include <ft/string.h>
#include <stdio.h>
#include <string.h>

#define TEST_ONE(s, c)                                                         \
	do {                                                                   \
		const char *__c = strrchr(s, c);                               \
		const char *__m = ft_strrchr(s, c);                            \
		if (__c != __m) {                                              \
			fprintf(                                               \
			    stderr,                                            \
			    "strrchr(\"%s\", 0x%hhx): expected %p, got %p\n",  \
			    s, (unsigned)c, (void *)__c, (void *)__m);         \
			assert(0);                                             \
		}                                                              \
	} while (0)

int main()
{
	TEST_ONE("", 0);
	TEST_ONE("hello world!\n", 'w');
	TEST_ONE("hello world!\n", '!');

	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 256; ++j) {
			char str[] = {(char)i, 0};
			TEST_ONE(str, j);
		}
	}
}
