#include<stdlib.h>
#include<stdio.h>

int main()
{
    char string[256];
    
    printf("Enter your name, big man: ");
    scanf("%256s", string);
    printf("Hello big boy, %s", string);
    exit(0);
}