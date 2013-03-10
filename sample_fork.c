#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(){
  int g=0;
  for(int i=0; i<2; i++){
    if(fork()==0){
      g++;
    }
  }
  
  
  printf("\n\n current pid : %d, current parent pid : %d, generation : %d\n\n",getpid(),getppid(),g);
  return 0;
}
