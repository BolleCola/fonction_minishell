#include "test.h"

int	main(int argc, char **argv, char **envp)
{
    char *test;
    char *path;
    int i;

    i = 0;
    while (envp[i])
    {
        test = envp[i];
        if (envp[i + 1])
            ft_printf("%s\n", test);
        else
            ft_printf("_=/usr/bin/env\n");
        i++;
    }
}