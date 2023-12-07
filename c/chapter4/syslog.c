#include<syslog.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

// /var/syslog or /var/log/syslog is outdated
// journactl is now used to watch system logs

int main()
{
    FILE *fp;

    fp = fopen("not here", "r");
    if (fp == NULL)
    {
        syslog(LOG_ERR|LOG_USER, "Oops - %s\n", strerror(errno));
        exit(1);
    }
    exit(0);
}