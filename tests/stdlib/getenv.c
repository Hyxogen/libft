#include <assert.h>
#include <ft/stdlib.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

static void test_one(const char *name)
{
	char *mine = ft_getenv(name);
	char *theirs = getenv(name);

	if (!theirs)
		assert(theirs == mine);
	else
		assert(!strcmp(mine, theirs));
}

int main(void)
{
	if (!environ)
		return 0;

	char buffer[256];

	for (char **env = environ; *env; ++env) {
		char *eq = strchr(*env, '=');
		if (!eq)
			continue;

		size_t len = eq - *env;
		assert(len < sizeof(buffer));

		memcpy(buffer, *env, len);
		buffer[len] = '\0';

		test_one(buffer);
	}
}
