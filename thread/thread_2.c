#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *f1()
{
printf("f1=%ld\n",pthread_self());
pthread_detach(pthread_self());
}

int main()
{
pthread_t pid;

pthread_create(&pid,NULL,&f1,NULL);
printf("main exit\n");
pthread_join(pid,NULL);
}
