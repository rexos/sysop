#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pthread.h>

int sum = 0;

void * func(void* arg){
  sum++;
}


int main(){
  printf("initial sum : %d\n",sum);
  pthread_t thread_id;
  int arg = NULL;
  pthread_create (&thread_id, NULL , &func, &arg);
  pthread_join(thread_id, NULL);
  printf("final sum : %d\n",sum);

  return 0;
}
