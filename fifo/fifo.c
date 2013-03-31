#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 512
#define AUTH_MODE ( S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH )

int main(){
  char buffer[BUFF_SIZE];

  unlink("myFIFO");

  if(mkfifo("myFIFO", AUTH_MODE) == -1){
    perror("fifo");
    unlink("myFIFO");
    exit(1);
  }
  
  if( fork() == 0 ){
    int fifo_fd = open("myFIFO", O_RDONLY);
    sleep(1);
    while( read( fifo_fd, buffer, sizeof(buffer)) != 0){
      printf("Child  >>>  My daddy told me : %s\n",buffer);
    }
  }
  else{
    int fd = open("myFIFO", O_WRONLY);
    for(int i=0; i < 3; i++ ){
      write( fd, "You're my son, bastard!", 23 );
      sleep(2);
    }
  }

  unlink("myFIFO");

  return 0;
}
