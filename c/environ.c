#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
    // ensure correct usage
    if (argc == 1 || argc > 3)
    {
        fprintf(stderr, "USAGE: enviroment variable [ENV_VAR]");
        return 1;
    }

    // declare strings var and value
    char *var, *value;

    var = argv[1];
    value = getenv(var);

    if (value)
    {
        printf("variable %s, has value %s\n", var, value);
    }
    else
    {
        printf("variable %s has no value\n", var);
    }

    if (argc == 3)
    {
        char *string;
        value = argv[2];
        string = malloc(strlen(var) + strlen(value) + 2);

        if (!string)
        {
            printf("Out of memory\n");
            return 2;
        }
        strcpy(string, var);
        strcat(string, "=");
        strcat(string, value);
        printf("Calling putnev() with %s\n", string);
        if (putenv(string) != 0)
        {
            fprintf(stderr, "putnev failed\n");
            free(string);
            return 3;
        }
    
        value = getenv(var);
        if (value)
        {
            printf("New variable %s, has value %s\n", var, value);
        }
        else
        {
            printf("variable %s has no value\n", var);
        }

        free(string);
        return 0;

    }

}