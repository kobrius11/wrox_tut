#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<pwd.h>

int main()
{
    uid_t uid;
    gid_t gid;
    
    struct passwd *pw;
    
    uid = getuid();
    gid = getgid();

    printf("USER: %s\n\tUID: %d\n\tGID: %d\n", getlogin(), uid, gid);
    pw = getpwuid(uid);
    printf("USER: %s\n\tPASS: %s\n\tUID: %d\n\tGID: %d\n\tNAME: %s\n\tHOME: %s\n\tSHELL: %s\n", 
        pw->pw_name, pw->pw_passwd, pw->pw_uid, pw->pw_gid, pw->pw_gecos, pw->pw_dir, pw->pw_shell);

    pw = getpwnam("root");
    printf("root password entry:\n");
    printf("USER: %s\n\tPASS: %s\n\tUID: %d\n\tGID: %d\n\tNAME: %s\n\tHOME: %s\n\tSHELL: %s\n", 
        pw->pw_name, pw->pw_passwd, pw->pw_uid, pw->pw_gid, pw->pw_gecos, pw->pw_dir, pw->pw_shell);
}
