#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
  
  
  char string[80];
  char *input = &string[0];
  size_t size = 80;
  while(true){
    getline(&input,&size,stdin);
    if(strcmp(string,"quit\n")==0){
      exit(0);
    }
    else{
      system(string);
    }
  }
  return 0;
}
