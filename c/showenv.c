#include<stdlib.h>
#include<stdio.h>

/*
    prints out enviroment variables
*/

extern char **environ;

int main(void)
{
    char **env = environ;

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
    return 0;
}