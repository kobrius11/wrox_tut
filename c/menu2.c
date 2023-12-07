#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

/*
    test this program out:
    menu2 > file
    and cat the file to see the output written in that file 
*/


char *menu[] = 
{
    "a - add new entry",
    "d - delete entry",
    "q - quit",
    NULL
};

int getchoice(char *prompt, char *choices[], FILE *in, FILE *out);

int main()
{
    int choice;
    FILE *input;
    FILE *output;

    input = fopen("/dev/tty", "r");
    output = fopen("/dev/tty", "w");

    if (!isatty(fileno(stdout)))
    {
        fprintf(stderr, "You are not in terminal!\n");
    }
    if (!input || !output)
    {
        fprintf(stderr, "Failed to open /dev/tty\n");
        exit(1);
    }

    do 
    {
        choice = getchoice("Please choice an option\n", menu, input, output);
        printf("You have chosen: %c\n", choice);
    } while( choice != 'q');
    exit(0);
}

int getchoice(char *prompt, char *choices[], FILE *in, FILE *out)
{
    int chosen = 0;
    int selected;
    char **options;

    do
    {
        fprintf(out, "%s\n", prompt);
        options = choices;
        while (*options)
        {
            fprintf(out, "%s\n", *options);
            options++;
        }
        do 
        {
            selected = fgetc(in);
        } while (selected == '\n');
        options = choices;
        while (*options)
        {
            if (selected == *options[0])
            {
                chosen = 1;
                break;
            }
            options++;
        }
        if (!chosen)
        {
            fprintf(out, "Invalid option selected, try again\n");
        }
    } while (!chosen);
    return selected;
}
