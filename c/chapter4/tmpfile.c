#include<stdio.h>
#include<stdlib.h>

int main()
{
    
    char tmpname[L_tmpnam];  //tmpname[] = "/tmp/fileXXXXXX";
    char *filename;
    FILE *tmpfp;
    
    filename = tmpnam(tmpname);  //mktemp(tmpname);./ 

    printf("tmpfile name is %s\n", filename);
    tmpfp = tmpfile();
    if (tmpfp != NULL)
    {
        printf("Created temporary file\n");
    }
    else 
    {
        fprintf(stderr, "tmpfile() failed\n");
    }
    exit(0);
}