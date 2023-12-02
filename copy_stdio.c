#include<stdlib.h>
#include<stdio.h>

int main()
{
    int c;
    FILE *in, *out;

    in = fopen("input/file.in", "r");
    out = fopen("file.out", "w");

    while ((c = fgetc(in)) != EOF)
    {
        fputc(c, out);
    }
    
    exit(0);
}