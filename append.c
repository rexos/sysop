#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
  int input_fd;
  int output_fd;
  char buf[512];
  if(argc!=3){
    printf("Usage: append file1 file2\n");
    exit(1);
  }
  if(open(argv[1], O_RDONLY)==-1){
    printf("Input file %s not found\n", argv[1]);
  }
  else{
    input_fd = open(argv[1], O_RDONLY);
  }
  output_fd = open(argv[2], O_WRONLY | O_CREAT | O_APPEND);
  int n;
  while((n=read(input_fd,buf,sizeof(buf)))>0){
    int r = lseek(output_fd,0,SEEK_END);
    write(output_fd,buf,n);
  }
  
  close(output_fd);
  close(input_fd);

  n = chmod(argv[2], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  printf("chmod exit code : %d\n",n);

  return 0;
}
