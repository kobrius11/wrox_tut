#include<unistd.h>
#include<stdio.h>
#include<time.h>

int main(void)
{
    int i;
    
    for (i = 0; i < 10; i++)
    {
        time_t the_time = time((time_t *)0);
        printf("The time is %ld\n", the_time);
        sleep(2);
    }   
    return 0;
}