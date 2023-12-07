#include<stdlib.h>
#include<unistd.h>
#include<syslog.h>

int main()
{
    openlog("logmask", LOG_PID|LOG_CONS, LOG_USER);
    syslog(LOG_INFO, "Informative message from %d", getpid());
    syslog(LOG_DEBUG, "Debug message should appear");
    setlogmask(LOG_UPTO(LOG_NOTICE));
    syslog(LOG_DEBUG, "Debug message should not appear");
    exit(0);

}
