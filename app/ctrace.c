#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

void new_strace(char* mode_sel, char* cmd_path){
  int mode = strcmp(mode_sel,"0");
  char path[100];

  if(mode == 0){
      printf("Modo automático\n");
      snprintf(path, sizeof path, "%s%s%s", "strace -c -U name,calls,errors,avg-time,time ", cmd_path, " 2>&1");
  }else{
      printf("Modo interactivo\n");
      snprintf(path, sizeof path, "%s%s%s", "strace ", cmd_path, " 2>&1");
      printf("Press ENTER key to step\n");
      mode = 1;
  }
  printf("Executing %s\n", path);

  FILE *fp;
  char line[1035];

  // Executes the command
  fp = popen(path, "r");
  if (fp == NULL) {
      printf("Failed to run command\n" );
      return;
  }

  // Reads the output of the command
  while (fgets(line, sizeof(line), fp) != NULL) {
      if (mode == 1){
          getchar();
          fseek(stdin,0,SEEK_END);
      }
      printf("%s", line);
      // Process each line here
  }

  pclose(fp);
}


int main( int argc, char *argv[] )
{
    if(argc != 3){
        printf("This program receives 2 arguments: mode and path\n");
        return 1;
    }

    new_strace(argv[1],argv[2]);

    return 0;
}
