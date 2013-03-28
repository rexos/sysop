#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <errno.h>
#include <cstdio>


int main(int argc, char *argv[]){
  int pfd[2];
  if(argc != 3){
    printf("Usage: %s arg_1 arg_2 \n", argv[0]);
    perror("argc");
    exit(1);
  }
  else{
    pipe(pfd);
    if(fork() == 0){
      close(pfd[0]);
      dup2(pfd[1], 1);
      execlp(argv[1],argv[1], NULL);
    }
    else{
      close(pfd[1]);
      dup2(pfd[0],0);
      execlp(argv[2],argv[2],NULL);
    }
  }
  return 0;
}
