#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("USAGE: /args [OPTIONS] [ARGUMENTS]");
        exit(1);
    }
    for (int i = 0; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            printf("option: %s\n", argv[i]+1);
        }
        else
            printf("argument %d: %s\n", i, argv[i]);
    }
    exit(0);
}