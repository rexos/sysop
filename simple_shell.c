#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){

  char *string;
  while(strcmp("quit",string)!=0){
  scanf("%s",string);
 
  system(string);
  }
  return 0;
}