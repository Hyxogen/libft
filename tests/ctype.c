#include <assert.h>
#include <ctype.h>
#include <limits.h>

#include <ft/ctype.h>

#define CHECK_BOOL(lhs, rhs) (!!(lhs) == !!(rhs))
#define CHECK_EQ(lhs, rhs) ((lhs) == (rhs))

#define TEST_X(ours, theirs, method) \
    do { \
        for (unsigned char i = 0; i < UCHAR_MAX; ++i) { \
            assert(method(ours(i), theirs(i)) && #ours); \
        } \
    } while (0)

#define TEST_ISFUNC(ours, theirs) TEST_X(ours, theirs, CHECK_BOOL)
#define TEST_EQFUNC(ours, theirs) TEST_X(ours, theirs, CHECK_EQ)


int main()
{
    TEST_ISFUNC(ft_isalnum, isalnum);
    TEST_ISFUNC(ft_isalpha, isalpha);
    TEST_ISFUNC(ft_iscntrl, iscntrl);
    TEST_ISFUNC(ft_isdigit, isdigit);
    TEST_ISFUNC(ft_isgraph, isgraph);
    TEST_ISFUNC(ft_islower, islower);
    TEST_ISFUNC(ft_isprint, isprint);
    TEST_ISFUNC(ft_ispunct, ispunct);
    TEST_ISFUNC(ft_isspace, isspace);
    TEST_ISFUNC(ft_isupper, isupper);
    TEST_ISFUNC(ft_isxdigit, isxdigit);
    TEST_ISFUNC(ft_isascii, isascii);
    TEST_ISFUNC(ft_isblank, isblank);
    TEST_EQFUNC(ft_toupper, toupper);
    TEST_EQFUNC(ft_tolower, tolower);
    return 0;
}
