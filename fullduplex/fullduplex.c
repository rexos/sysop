#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

  int parch[2];
  int chpar[2];

  char buffer[100];

  pipe(parch);
  pipe(chpar);

  
  if(fork() == 0){
    close(parch[1]);
    close(chpar[0]);
    write(chpar[1], "Hey daddy!\0", 10);
    sleep(1);
    read(parch[0], buffer, sizeof(buffer));
    printf("Child   ----->  My father told me : %s\n",buffer);
  }
  else{

    close(parch[0]);
    close(chpar[1]);
    read(chpar[0],buffer,sizeof(buffer));
    printf("Parent ----->  My son told me : %s\n",buffer);
    write(parch[1], "Fuck you bastard!\0", 17);
    sleep(3);
  }
  
  return 0;
}
