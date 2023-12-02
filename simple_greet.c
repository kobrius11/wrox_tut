#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2 )
    {
        printf("USAGE: simple_greet [NAME]");
        exit(1);
    }
    printf("Hello mister boy %s", argv[1]);
    exit(0);
}
