#include<sys/utsname.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
    char computer[256];
    struct utsname uts;

    if ((gethostname(computer, 255) != 0) || (uname(&uts) < 0 ))
    {
        perror("Could not get host information\n");
        exit(1);
    }

    printf("COMPUTER: %s\n\tSYSTEM: %s\n\tHARDWARE: %s\n\tNODE: %s\n\tVERSION: %s\n\tRELEASE: %s\n", 
        computer, uts.sysname, uts.machine, uts.nodename, uts.version, uts.release);

    exit(0);
    

}