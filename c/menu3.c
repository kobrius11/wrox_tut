#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<termios.h>

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
    FILE *in_fp;
    FILE *out_fp;
    int choice;
    struct termios initialrsettings, newrsettings;

    in_fp = fopen("/dev/tty", "r");
    out_fp = fopen("/dev/tty", "w");
    if (!isatty(fileno(stdout)))
    {
        fprintf(stderr, "You are not in terminal\n");
    }

    if (!in_fp||!out_fp)
    {
        fprintf(stderr, "Could not open /dev/tty\n");
        exit(1);
    }
    // Get current terminal settings, puts them into structure
    tcgetattr(fileno(in_fp), &initialrsettings);
    // Copies currents settings to other variable, so changes can be made safely
    newrsettings = initialrsettings;
    // sets ICANON bit to 0
    newrsettings.c_lflag &= ~ICANON;
    // sets ECHO bit to 0
    newrsettings.c_lflag &= ~ECHO;
    //
    newrsettings.c_cc[VMIN] = 1;
    //
    newrsettings.c_cc[VTIME] = 0;
    if (tcsetattr(fileno(in_fp), TCSANOW, &newrsettings) != 0)
    {
        fprintf(stderr, "Could not set attributes\n");
    }

    do 
    {
        choice = getchoice("Enter your choice: ", menu, in_fp, out_fp);
        printf("\tYou have chosen: %c\n", choice);
    } while (choice != 'q');
    tcsetattr(fileno(in_fp), TCSANOW, &initialrsettings);
    exit(0);
}

int getchoice(char *prompt, char *choices[], FILE *in, FILE *out)
{
    int chosen = 0;
    int selected;
    char **option;

    do 
    {
        fprintf(out, "%s\n", prompt);
        option = choices;
        
        // Print out options
        while (*option)
        {
            fprintf(out, "%s\n", *option);
            option++;
        }
        // Get single char(user input) from input file(stdin)
        do
        {
            selected = fgetc(in);
        } while (selected == '\n' || selected == '\r');
        option = choices;
        // Check if option is selected
        while (*option)
        {
            if (selected == *option[0])
            {
                chosen = 1;
                break;
            }
        option++;
        }
        if (!chosen)
        {
            fprintf(out, "Invalid choice: %c, Please select valid choice\n", selected);
        }
    }while (!chosen);
    return selected;
}