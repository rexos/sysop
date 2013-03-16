#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char * argv[]){
  
  int input_fd;
  int output_fd;
  
  char buf[512];

  if(argc!=3){
    printf ("Usage : copy 'input filename' 'output filename'\n");
    exit(1);
  }
  else{
    input_fd = open(argv[1], O_RDONLY);
    output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC);
  }
  int n=0;
  while((n=read(input_fd,buf,(int)sizeof(buf)))>0){
    write(output_fd,buf,n);
  }
  
  close(output_fd);
  close(input_fd);
  return 0;
}
