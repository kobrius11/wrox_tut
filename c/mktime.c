#include<stdio.h>
#include<time.h>

struct tm *tm_ptr;

int main()
{
    // create long int variable
    time_t time_raw;
    (void) time(&time_raw);
    // populates tm structure
    tm_ptr = localtime(&time_raw);
    // create time_t(long int) variable from tm structure 
    time_raw = mktime(tm_ptr);
    // prints value of ctime()
    printf("ctime gives: \n\t%s", ctime(&time_raw));
    return 0;
}