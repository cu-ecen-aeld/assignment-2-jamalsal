#include<stdio.h>
#include<syslog.h>

int main(int argc, char *argv[]){
  openlog("Wlog",0,LOG_USER);

  if (argc != 3){
    printf("incorrect number of arguments\n");
    syslog(LOG_ERR,"Incorrect number of arguments");
    closelog();
    return 1;
  }
  
  char *writefile = argv[1];
  char *writestr = argv[2];
  FILE *w_file = fopen(writefile, "w+");

  if (w_file==NULL){
    printf("Error: File does not exist.\n");
    syslog(LOG_ERR,"Error, could not open %s",writefile);
    closelog();
    return 1;
  }

  fprintf(w_file,"%s",writestr);
  syslog(LOG_DEBUG, "Writing %s to %s", writestr,writefile);
  fclose(w_file);
  closelog();
  return 0;
}

