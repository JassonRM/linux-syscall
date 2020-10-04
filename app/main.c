#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] )
{
    if(argc != 3){
        return 1;
    }
    char path[100];
    snprintf(path, sizeof path, "%s%s%s", "strace ", argv[2], " 2>&1");
    printf("Executing %s\n", path);

    FILE *fp;
    char line[1035];

    /* Open the command for reading. */
    fp = popen(path, "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }

    /* Read the output a line at a time - output it. */
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
//        Process each line here
    }

    /* close */
    pclose(fp);
}
