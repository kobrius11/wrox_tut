#include<stdlib.h>
#include<stdio.h>

int main()
{
    char s[256];
    int n;
    float f;
    char c;
    
    // example input: Hello, 1234, 5.678, X, string to the end of the line
    scanf("Hello,%d,%g, %c, %[^\n]", &n,&f,&c,s);
    printf("digit: %d\nFloat: %g\nChar: %c\nString: %s\n", n,f,c,s);
    exit(0);
    }