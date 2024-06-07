#include <assert.h>
#include <ft/string.h>
#include <stdlib.h>
#include <string.h>

static void test_one(const char *str, const char *delim)
{
	char *cstr = strdup(str);
	char *mstr = strdup(str);

	char *cstringp = cstr, *mstringp = mstr;

	while (1) {
		char *org_cstringp = cstringp;
		char *org_mstringp = mstringp;

		char *cres = strsep(&cstringp, delim);
		char *mres = ft_strsep(&mstringp, delim);

		if (!cstringp) {
			assert(!mstringp);
			break;
		}

		assert(mres == org_mstringp);

		assert((cstringp - org_cstringp) == (mstringp - org_mstringp));

		assert(!strcmp(cres, mres));
	}

	free(cstr);
	free(mstr);
}

int main(void)
{
	char *null = NULL;
	assert(ft_strsep(&null, NULL) == NULL);
	assert(ft_strsep(&null, " ") == NULL);

	test_one("hello world", " ");
	test_one("hello world", "helloworld ");
	test_one("hello world", "");
	test_one("hello world", "\0");
	test_one("hello world", "\t\v");
	test_one("he\x11llo\x12wo\x12rld\x12", "\x12");
}
