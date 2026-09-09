#include "autotest.h" 

int autotest1(void)
{
    char *str = malloc(100), res[] = "Hello%20World";
    int result;
    strcpy(str, "Hello World");
    result = str_equal(main_func(str), res);
    free(str);
    return result;
}

int autotest2(void)
{
    char *str = malloc(100), res[] = "%20%20test%20%20";
    int result;
    strcpy(str, "  test  ");
    result = str_equal(main_func(str), res);
    free(str);
    return result;
}
