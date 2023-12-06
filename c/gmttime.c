#include<stdio.h>
#include<unistd.h>
#include<time.h>

struct tm *tm_ptr;

int main(void)
{
    time_t the_time;

    (void) time(&the_time);
    tm_ptr = gmtime(&the_time);

    printf("Raw time: %ld\n", the_time);
    printf("GMT time gives:\n");
    printf(" Date: %02d/%02d/%02d\n", 
        tm_ptr->tm_year, tm_ptr->tm_mon, tm_ptr->tm_mday);
    
    printf(" time: %02d:%02d:%02d\n",
        tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
    return 0;

}

