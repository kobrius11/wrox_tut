#include<stdio.h>
#include<time.h>

struct tm *tm_ptr;

int main()
{
    time_t time_raw = time((time_t *)0);
    tm_ptr = localtime(&time_raw);

    printf("Raw time: %ld\n", time_raw);
    printf("Local time:\n");
    printf(" DATE: %02d/%02d/%02d\n",
        tm_ptr->tm_year, tm_ptr->tm_mon, tm_ptr->tm_mday);
    printf(" TIME: %02d:%02d:%02d\n",
        tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
    return 0;
}