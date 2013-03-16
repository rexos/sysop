#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int size=0;
  int fd;

  if(argc!= 2){
    printf("\n\nUsage: size 'file'\n\n");
    exit(1);
  }
  
  else if (fd = (open(argv[1],0,O_RDONLY))==-1){
    printf("\n\n File not found!\n\n");
    exit(1);
  }
  else{
    fd = (open(argv[1],0,O_RDONLY));
    size = (int)(lseek(fd,0,SEEK_END));
    printf("\n\nsize : %d\n\n", size);
  }
  
  close(fd);


  return 0;
}
