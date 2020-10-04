#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] )
{
    if(argc != 3){
        printf("This program receives 2 arguments: mode and path");
        return 1;
    }
    char path[100];
    snprintf(path, sizeof path, "%s%s%s", "strace ", argv[2], " 2>&1");
    printf("Executing %s\n", path);

    FILE *fp;
    char line[1035];

    // Executes the command
    fp = popen(path, "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        return 1;
    }

    // Reads the output of the command
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        // Process each line here
    }

    pclose(fp);
    return 0;
}
