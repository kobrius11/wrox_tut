#include<sys/types.h>
#include<sys/resource.h>
#include<sys/time.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<math.h>

// compile with gcc -o compiled/limits c/limits.c -lm -Wall -Wpedantic -Wextra 

void work(void);

int main()
{
    struct rusage r_usage;
    struct rlimit r_limit;
    int priority;

    work();
    getrusage(RUSAGE_SELF, &r_usage);

    printf("CPU USAGE:\n\tUSER: %ld:%06ld\n\tSYS: %ld:%06ld\n",
        r_usage.ru_utime.tv_sec, r_usage.ru_utime.tv_usec,
        r_usage.ru_stime.tv_sec, r_usage.ru_stime.tv_usec);
    
    priority = getpriority(PRIO_PROCESS, getpid());
    printf("CURRENT PRIORITY: %i", priority);

    getrlimit(RLIMIT_FSIZE, &r_limit);
    printf("FSIZE LIMIT:\n\tSOFT: %ld\n\tHARD: %ld\n",
        r_limit.rlim_cur, r_limit.rlim_max);
    

    r_limit.rlim_cur = 2048;
    r_limit.rlim_max = 4096;
    printf("Setting a 2K file size limit\n");
    setrlimit(RLIMIT_FSIZE, &r_limit);
    work();

    exit(0);
}

void work(void)
{
    int i;
    double x = 4.5;
    FILE *fp;

    fp = tmpfile();
    for (i=0; i<10000; i++)
    {
        fprintf(fp, "Do some output\n");
        if (ferror(fp))
        {
            fprintf(stderr, "Error writing to temporary file\n");
            exit(0);
        }
    }
    for (i=0; i<10000; i++)
    {
        x = log(x*x + 3.21);
    }
}
